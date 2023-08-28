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
    void Draw();
    void Update();
    void Reset(int m_W, int m_H, int m_cellSize);
    void FillCell(Cell* cell);
    void FillCell(Cell* cell, SDL_Color color);
    void CreateGrid();
    int GetCellSize();
    Cell* FindCell(GLOBAL::MATH::Vector2D m_position);
protected:
    virtual void DrawCell(Cell* cell);
    int width,height,cellSize,offSetX,offSetY;
    SDL_Renderer* renderer;
private:
    std::vector<Cell*> cells;
};