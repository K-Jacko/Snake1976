#pragma once
#include "Global.h"

class Cell
{
public:
    Cell(int m_x, int m_y);
    GLOBAL::MATH::Vector2D position;
    bool isActive;
private:

};

class Grid
{
public:
    Grid(int m_W, int m_H, int cellSize, SDL_Renderer* m_renderer);
    ~Grid();
    void DrawGrid();
    void Update();
    void DrawCell(Cell* cell);
    Cell* FindCell();
    void FillCell(Cell* cell);
    std::vector<Cell*> cells;

private:
    void CreateGrid();
    int width,height,cellSize,offSetX,offSetY;
    SDL_Renderer* renderer;
};