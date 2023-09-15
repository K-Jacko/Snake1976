#include <iostream>
#include "Game.h"

int main(int argc, char* args[]) {
    SDL_SetMainReady();
    auto game = new Game();
    Game::Init();
    while(Game::isRunning())
    {
        Game::Event();
        Game::Update();
        Game::Draw();
    }
    return 0;
}
