#pragma once
#include "Grid.h"

class SnakeCell : public Cell
{
    SnakeCell(int m_x, int m_y);
    ~SnakeCell();
    enum SnakeCellType{
        HEAD,
        TAIL
    };
    GLOBAL::MATH::Vector2D position;

};
class SnakeGrid : public Grid
{
    SnakeGrid();
    ~SnakeGrid();
    void DrawGrid() override;
    void Update() override;
private:
    void CreateGrid() override;
    void DrawCell(Cell* cell) override;
    void DrawSnakeCell(SnakeCell* cell);
};

