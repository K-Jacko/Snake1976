#pragma once
#include "Global.h"

class Cell
{
public:
    Cell(int m_x, int m_y);
    GLOBAL::MATH::Vector2D position;
private:

};

class Grid
{
public:
    Grid();
    ~Grid();
    virtual void DrawGrid();
    virtual void Update();
    void Reset(int m_W, int m_H, int m_cellSize);
    std::vector<Cell*> cells;
protected:
    virtual void CreateGrid();
    virtual void DrawCell(Cell* cell);
    Cell* FindCell();
    void FillCell(Cell* cell);
    int width,height,cellSize,offSetX,offSetY;
    SDL_Renderer* renderer;
};