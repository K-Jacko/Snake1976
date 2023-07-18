#pragma once
#include "Global.h"

class WindowLayer
{
public:
    WindowLayer();
    ~WindowLayer();
    SDL_Window* CreateWindow();
    SDL_Renderer* CreateRenderer();
    SDL_Window* GetWindow();
    SDL_Renderer* GetRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

};