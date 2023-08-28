#pragma once
#include "SceneManager.h"
#include "InputLayer.h"
#include "WindowLayer.h"
#include "GridLayer.h"
#include "Buttons.h"
#include "UILayer.h"
#include "snake1976/Snake.h"
#include <SDL.h>

class Game
{
public:
    Game();
    ~Game();
    static void Init();
    static void InitMainSystems();
    static void InitSubSystems();
    static void Event();
    static void Update();
    static void Draw();
    static void End();
    static bool isRunning();
    static SDL_Event event;
private:
    static bool running;
};
