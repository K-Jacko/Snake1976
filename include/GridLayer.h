#pragma once
#include "Global.h"
#include "Grid.h"

class GridLayer
{
public:
    GridLayer();
    ~GridLayer();
    static GridLayer& Instance();
    void Init();
    void Update();
    void Draw();

private:
    Grid* mainGrid;
    SDL_Renderer* renderer;
};