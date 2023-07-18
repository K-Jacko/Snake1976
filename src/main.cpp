#include <iostream>
#include "Game.h"
Game* game = nullptr;

int main(int argc, char* args[]) {
    SDL_SetMainReady();
    game = new Game();
    game->Init();
    while(game->isRunning())
    {
        game->Event();
        game->Update();
        game->Draw();
    }
    return 0;
}
