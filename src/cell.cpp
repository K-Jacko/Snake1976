#include "Cell.h"

Cell::Cell(){
    position = {0,0};
}

Cell::Cell(int m_x, int m_y) {
    position.x = m_x;
    position.y = m_y;
}