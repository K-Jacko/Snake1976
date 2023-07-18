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
}
void Game::Update() {
inputLayer->Update();
gridLayer->Update();
}
void Game::Draw() {
    SDL_RenderClear(GetWindowLayer()->GetRenderer());
    gridLayer->Draw();
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