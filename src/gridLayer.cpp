#include <valarray>
#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    renderer = nullptr;
    mainGrid = nullptr;
}

GridLayer::~GridLayer(){
    Reset();
    renderer = nullptr;
    mainGrid = nullptr;
}
GridLayer& GridLayer::Instance() {
    static GridLayer gridLayer;
    return gridLayer;
}
void GridLayer::Init()
{
    mainGrid = new Grid();
}
void GridLayer::Update() {

}
void GridLayer::Draw() {

    if(mainGrid != nullptr){
        mainGrid->DrawGrid();
    }
}
void GridLayer::Reset() {
    delete mainGrid;
}
void GridLayer::LoadNewGrid(int m_x, int m_y, int m_cellSize){
    mainGrid->Reset(m_x,m_y,m_cellSize);
}