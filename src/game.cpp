#include "Game.h"
#include <iostream>
#include <SDL.h>

bool Game::running;

GLOBAL::GAME::Scene* SceneLayer::currentScene;
MenuScene SceneLayer::menuScene;
GameScene SceneLayer::gameScene;
HighScoreScene SceneLayer::highScoreScene;
GameOverScene SceneLayer::gameOverScene;



Game::Game(){
    running = true;
}
Game::~Game() = default;

void Game::Init() {
    InputLayer::Instance();
    AudioLayer::Instance();
    SceneLayer::Instance();
}
void Game::Event() {
    EventLayer::Instance().Poll();
    switch (EventLayer::Instance().GetEvent().type) {
        case SDL_QUIT:
            End();
            break;
        case SDL_KEYDOWN:
            switch (EventLayer::Instance().GetEvent().key.keysym.sym) {
                case SDLK_ESCAPE:
                    End();
                    break;
            }
            break;
        case SDL_USEREVENT:
            switch (EventLayer::Instance().GetEvent().user.code) {
                case 101:
                    End();
                    break;
            }
    }
}
void Game::Update() {
    InputLayer::Instance().Update();
    AudioLayer::Instance().Update();
    SceneLayer::Instance().Update();
}
void Game::Draw() {
    SDL_RenderClear(WindowLayer::Instance().GetRenderer());
    SceneLayer::Instance().Draw();
    SDL_RenderPresent(WindowLayer::Instance().GetRenderer());

}
bool Game::isRunning() {
    return running;
}
void Game::End() {
    SDL_Quit();
    std::cout << "Game Cleared" << std::endl;
    running = false;
}


