#include "Game.h"
#include "SceneManager.h"
#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"

UIButton button;
Game::Game(){
    running = true;
    sceneManager = SceneManager();
    windowLayer = WindowLayer();
    inputLayer = InputLayer();
    gridLayer  = GridLayer();
    uiLayer = UILayer();
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
    sceneManager.Instance().Init();
    inputLayer.Instance().Init(&event);
    gridLayer.Instance().Init(windowLayer.Instance().GetRenderer());
    uiLayer.Instance().Init(windowLayer.Instance().GetRenderer());
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
inputLayer.Instance().Update();
gridLayer.Instance().Update();
uiLayer.Instance().Update(inputLayer);
}
void Game::Draw() {
    SDL_RenderClear(windowLayer.Instance().GetRenderer());
    gridLayer.Instance().Draw();
    uiLayer.Instance().Draw();
    SDL_RenderPresent(windowLayer.Instance().GetRenderer());
}

bool Game::isRunning() const {
    return running;
}
void Game::End() {
    SDL_Quit();
    std::cout << "GAME Cleared" << std::endl;
    running = false;
}
