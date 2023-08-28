#pragma once
#include "GridLayer.h"
#include "InputLayer.h"
#include "Timer.h"

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
    explicit Snake(Grid* m_grid);
    ~Snake();
    void Draw();
    void Update();
private:
    GLOBAL::MATH::Vector2D GetInput();
    Timer timer;
    int snakeLength = 7;
    Grid* grid;
    InputLayer* input;
    std::vector<SnakeCell*> cells;
};

