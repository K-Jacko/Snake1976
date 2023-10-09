#pragma once
#include "./layers/InputLayer.h"
#include "./layers/WindowLayer.h"
#include "./layers/GridLayer.h"
#include "./layers/UILayer.h"
#include "./layers/EventLayer.h"
#include "./layers/SceneLayer.h"
#include "./layers/AudioLayer.h"
#include <SDL.h>

class Game
{
public:
    Game();
    ~Game();
    static Game& Instance(){
        static Game game;
        return game;
    }
    void Init();
    static void Event();
    static void Update();
    static void Draw();
    static void End();
    static bool isRunning();
private:
    static bool running;
};
