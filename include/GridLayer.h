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
    void Reset();
    void LoadNewGrid(int m_x, int m_y, int m_cellSize);
private:
    Grid* mainGrid;
    SDL_Renderer* renderer;
};