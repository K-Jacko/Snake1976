#pragma once
#include "Cell.h"

enum SnakeCellType{
    OFF,
    HEAD,
    TAIL,
};

class SnakeCell : public Cell
{
public:
    SnakeCell()= default;
    SnakeCell(int m_x, int m_y){position={m_x,m_y};};
    ~SnakeCell()= default;
    SnakeCellType cellType{};
};