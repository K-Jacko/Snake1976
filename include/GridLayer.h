#pragma once
#include "Global.h"
#include "Grid.h"

class GridLayer
{
public:
    GridLayer();
    ~GridLayer();
    void Init();
    void Update();
    void Draw();
    void LoadNewGrid(int m_x, int m_y, int m_cellSize);
    Grid* mainGrid;
private:
    SDL_Renderer* renderer;
};