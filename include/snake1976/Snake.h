#pragma once
#include "Grid.h"
enum SnakeCellType{
    OFF,
    HEAD,
    TAIL,
};

class SnakeCell : public Cell
{
public:
    SnakeCell();
    SnakeCell(int m_x, int m_y);
    ~SnakeCell();
    SnakeCellType cellType;
};
class Snake
{
public:
    Snake();
    ~Snake();
    void DrawSnake();
    void Update();
private:
    void CreateGrid();
    void DrawCell(Cell* cell);
    void DrawSnakeCell(SnakeCell* cell);
    std::vector<GLOBAL::MATH::Vector2D> positions;
    SnakeCell* head;
};

