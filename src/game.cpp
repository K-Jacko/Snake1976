#include "Game.h"
#include "SceneManager.h"
#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"

Game::Game(){
    running = true;
    sceneManager = new SceneManager;
    windowLayer = new WindowLayer;
    inputLayer = new InputLayer;
    gridLayer = new GridLayer;
}
Game::~Game() = default;
void Game::Init() {
    InitSubSystems();
    InitMainSystems();
}
void Game::InitMainSystems() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){std::cout << "ERROR" << SDL_GetError() << std::endl;}
    else{std::cout << "Video Systems :: Initialised!" << std::endl;}
    if(!IMG_Init(IMG_INIT_PNG)){std::cout << "ERROR" << SDL_GetError() << std::endl;}
    else{std::cout << "IMG :: Systems Initialised!" << std::endl;}
    if(TTF_Init() != 0){std::cout << "ERROR" << SDL_GetError() << std::endl;}
    else{std::cout << "Text :: Systems Initialised!" << std::endl;}
}
void Game::InitSubSystems() {
    sceneManager->Init();
    inputLayer->Init(&event);
    gridLayer->Init(GetWindowLayer()->GetRenderer());
    auto startButton = UIButton(10,1,ButtonSize::Medium,"Text");
    uiButtons.push_back(startButton);
//    auto firstButton = UIButton(Global::SCREEN::WIDTH - Global::SCREEN::WIDTH , 0,ButtonSize::Medium,"Text");
//    uiButtons.push_back(firstButton);
//    auto secondButton = UIButton(0, Global::SCREEN::HEIGHT - Global::SCREEN::HEIGHT,ButtonSize::Medium,"Text");
//    uiButtons.push_back(secondButton);
//    auto thirdButton = UIButton( Global::SCREEN::WIDTH  - Global::SCREEN::WIDTH , Global::SCREEN::HEIGHT - Global::SCREEN::HEIGHT,ButtonSize::Medium,"Text");
//    uiButtons.push_back(thirdButton);
}
void Game::Event() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            End();
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    End();
                    break;
            }
    }
    for (UIButton button : uiButtons) {
        button.HandleEvent(&event);
    }
}
void Game::Update() {
inputLayer->Update();
gridLayer->Update(*inputLayer);
}
void Game::Draw() {
    SDL_RenderClear(GetWindowLayer()->GetRenderer());
    gridLayer->Draw();
    for (UIButton button : uiButtons) {
        button.Init(GetWindowLayer()->GetRenderer());
        button.Draw(&event);
    }
    SDL_RenderPresent(GetWindowLayer()->GetRenderer());
}
WindowLayer* Game::GetWindowLayer() {
    return windowLayer;
}
bool Game::isRunning() const {
    return running;
}
void Game::End() {
    SDL_Quit();
    std::cout << "GAME Cleared" << std::endl;
    running = false;
}