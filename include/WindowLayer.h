#pragma once
#include "Global.h"

class WindowLayer
{
public:
    WindowLayer();
    ~WindowLayer();
    static WindowLayer& Instance();
    void Init();
    SDL_Window* CreateWindow();
    SDL_Renderer* CreateRenderer();
    SDL_Window* GetWindow();
    SDL_Renderer* GetRenderer();
    void Reset();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

};