#pragma once
#include "SceneManager.h"
#include "InputLayer.h"
#include <SDL.h>

class Game
{
public:
    Game();
    ~Game();
    void Init();
    void InitMainSystems();
    void InitSubSystems();
    void Event();
    void Update();
    void Draw();
    void End();
    bool isRunning();
    SceneManager* sceneManager;
    SDL_Event event{};
    InputLayer* inputLayer;
private:
    bool running;

};
