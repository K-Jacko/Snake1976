#pragma once
#include "SceneManager.h"
#include "InputLayer.h"
#include "WindowLayer.h"
#include "GridLayer.h"
#include <SDL.h>

class Game
{
public:
    Game();
    ~Game();
    void Init();
    static void InitMainSystems();
    void InitSubSystems();
    void Event();
    void Update();
    void Draw();
    void End();
    WindowLayer* GetWindowLayer();
    [[nodiscard]] bool isRunning() const;
    SDL_Event event{};
private:
    bool running;
    SceneManager* sceneManager;
    WindowLayer* windowLayer;
    InputLayer* inputLayer;
    GridLayer* gridLayer;
};
