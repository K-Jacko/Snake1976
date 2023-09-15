#include <valarray>
#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    mainGrid = new Grid(0,0,0);
}
GridLayer::~GridLayer() {
}
GridLayer &GridLayer::Instance() {
    static GridLayer instance;
    return instance;
}
void GridLayer::Init() {

}
void GridLayer::Update() {

}
void GridLayer::Draw() {
        mainGrid->Draw();
}
void GridLayer::LoadNewGrid(int m_x, int m_y, int m_cellSize){
    delete(mainGrid);
    mainGrid = new Grid(m_x,m_y,m_cellSize);
}


