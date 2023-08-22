#pragma once
#include "Global.h"

class Cell
{
public:
    Cell();
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
    void FillCell(Cell* cell);
    void FillCellByPosition(GLOBAL::MATH::Vector2D m_Position);
    virtual void CreateGrid();
protected:
    virtual void DrawCell(Cell* cell);
    Cell* FindCell();
    int width,height,cellSize,offSetX,offSetY;
    SDL_Renderer* renderer;
private:
    std::vector<Cell*> cells;
};