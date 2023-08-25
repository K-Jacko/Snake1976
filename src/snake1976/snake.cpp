#include "snake1976/Snake.h"
#include "GridLayer.h"
#include <chrono>

Snake::Snake(Grid* m_grid) {
    grid = m_grid;
    input = &InputLayer::Instance();
    auto head = new SnakeCell;
    head->cellType = SnakeCellType::HEAD;
    head->position = GLOBAL::MATH::Vector2D(GLOBAL::SCREEN::SCREEN_WIDTH/2,GLOBAL::SCREEN::SCREEN_HEIGHT/2);
    cells.push_back(head);

    for (int i = 1; i < snakeLength; ++i) {
        auto tail = new SnakeCell(head->position.x, head->position.y);
        tail->cellType = SnakeCellType::TAIL;
        tail->position = GLOBAL::MATH::Vector2D(head->position.x, head->position.y + i * grid->GetCellSize());
        cells.push_back(tail);
    }
}
Snake::~Snake() {
    cells.clear();
    cells.shrink_to_fit();
}
void Snake::Draw() {
    for (int i = 0; i < cells.size(); ++i) {
        grid->FillCell(grid->FindCell(cells[i]->position));
    }
}
void Snake::Update() {
    timer.Reset();
    if(timer.Elapsed() >= 1.0){
        for (int i = snakeLength - 1; i > 1; i--) {
            cells[i]->position = cells[i - 1]->position;
        }
        cells[0]->position += GLOBAL::MATH::Vector2D(GetInput()->x,GetInput()->y);
        timer.Reset();
    }


//    if (deltaTime >= 100){
//        if (!input->GetKeyInputs().empty()) {
//            cells[0]->position += GLOBAL::MATH::Vector2D(input->GetKeyInputs()[0]->x, input->GetKeyInputs()[0]->y);

//        }
//
//        cells[0]->position.Add(GLOBAL::MATH::Vector2D(0,-1));
//        for (int i = cells.size() - 1; i > 0; --i) {
//            cells[i]->position = cells[i - 1]->position;
//        }
//
//
//    }
}
GLOBAL::MATH::Vector2D* Snake::GetInput() {
    GLOBAL::MATH::Vector2D* storedDirection;
    if(!input->GetKeyInputs().empty())
    {
        storedDirection = input->GetKeyInputs()[0];
        return storedDirection;

    }else{
        return new GLOBAL::MATH::Vector2D(0,-1);
    }
}
SnakeCell::SnakeCell() {

}
SnakeCell::SnakeCell(int m_x, int m_y) {

}
