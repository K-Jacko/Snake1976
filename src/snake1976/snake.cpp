#include "snake1976/Snake.h"
#include "GridLayer.h"
#include "InputLayer.h"

Snake::Snake() {
    CreateGrid();
    head = new SnakeCell(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT / 2);
    head->cellType = SnakeCellType::HEAD;
}
Snake::~Snake(){
    positions.clear();
    positions.shrink_to_fit();
}
void Snake::DrawSnake() {
    //GridLayer::Instance().mainGrid->FillCellByPosition(head->position);
}
void Snake::Update() {
    InputLayer& inputLayer = InputLayer::Instance();
//    GLOBAL::MATH::Vector2D vec =
//    auto keyInput = std::find(inputLayer.GetKeyInputs().begin(), inputLayer.GetKeyInputs().end(),)
}
void Snake::CreateGrid() {
    //GridLayer::Instance().LoadNewGrid(30,40,24);

}
void Snake::DrawCell(Cell *cell) {

}
void Snake::DrawSnakeCell(SnakeCell *cell) {

}
SnakeCell::SnakeCell() {

}
SnakeCell::SnakeCell(int m_x, int m_y) {
    position = {m_x,m_y};
}
