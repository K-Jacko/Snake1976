#include <iostream>
#include "Game.h"
Game* game;

int main() {
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
