#include <iostream>
#include "Game.h"

int main(int argc, char* args[]) {
    SDL_SetMainReady();
    Game::Instance().Init();
    while(Game::isRunning())
    {
        Game::Event();
        Game::Update();
        Game::Draw();
    }
    return 0;
}
