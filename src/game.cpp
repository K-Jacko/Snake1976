#include "Game.h"
#include "SceneManager.h"
#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"

Game::Game(){
    running = false;
    sceneManager = nullptr;
}
Game::~Game() {

}
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
    sceneManager = new SceneManager;
    sceneManager->Init();

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

}
void Game::Draw() {

}

bool Game::isRunning() {
    return running;
}
void Game::End() {
    running = false;
}