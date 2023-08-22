#include "Game.h"
#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SceneManager.h"

bool Game::running;
WindowLayer* windowLayer;

Game::Game(){
    running = true;
}
Game::~Game() = default;
Game& Game::Instance() {
    static Game game;
    return game;
}
void Game::Init() {
    InitMainSystems();
    InitSubSystems();

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
    WindowLayer::Instance().Init();
    InputLayer::Instance().Init(&event);
    SceneManager::Instance().Init();
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
    InputLayer::Instance().Update();
    SceneManager::Instance().Update();
}
void Game::Draw() {
    SDL_RenderClear(WindowLayer::Instance().GetRenderer());
    SceneManager::Instance().Draw();
    SDL_RenderPresent(WindowLayer::Instance().GetRenderer());

}

bool Game::isRunning() {
    return running;
}
void Game::End() {
    SDL_Quit();
    std::cout << "GAME Cleared" << std::endl;
    running = false;
}
