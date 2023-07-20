#pragma once
#include "SceneManager.h"
#include "InputLayer.h"
#include "WindowLayer.h"
#include "GridLayer.h"
#include "Buttons.h"
#include "UILayer.h"
#include <SDL.h>

class Game
{
public:
    Game();
    Game& Instance();
    ~Game();
    void Init();
    static void InitMainSystems();
    void InitSubSystems();
    void Event();
    static void Update();
    static void Draw();
    static void End();
    static void LoadScenes();
    static bool isRunning();
    SDL_Event event{};
private:
    static bool running;
};
