#pragma once
#include "Global.h"
#include "Cell.h"

class Grid
{
public:
    Grid(int m_W, int m_H, int m_cellSize);
    ~Grid();
    void Draw();
    void Update();
    int GetWidth(){return width;}
    int GetHeight(){return height;}
    void FillCell(Cell* cell, SDL_Color color);
    int GetCellSize(){return cellSize;}
    Cell* FindCell(GLOBAL::MATH::Vector2D m_position);
protected:
    int width,height,cellSize,offSetX,offSetY;
    SDL_Renderer* renderer;
private:
    std::vector<Cell*> cells;
};