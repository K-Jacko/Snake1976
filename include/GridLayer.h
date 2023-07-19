#pragma once
#include "Global.h"
class GridLayer
{
public:
    GridLayer();
    GridLayer& Instance();
    void Init(SDL_Renderer* m_renderer);
    void Update();
    void Draw();
    int GetWidth()
    {
        return width;
    }
    int GetHeight()
    {
        return height;
    }
    int GetCellSize()
    {
        return cellSize;
    }
private:
    int width;
    int height;
    int cellSize;
    SDL_Renderer* renderer;
    std::vector<Global::MATH::Vector2D> cells;
};