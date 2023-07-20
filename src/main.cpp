#include <iostream>
#include "Game.h"
Game* game = nullptr;

int main(int argc, char* args[]) {
    SDL_SetMainReady();
    Uint32 startTime = SDL_GetTicks();
    game = new Game();
    game->Init();
    while(game->isRunning())
    {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - startTime) / 1000.0f;
        game->Event();
        game->Update();
        game->Draw();
    }
    return 0;
}
