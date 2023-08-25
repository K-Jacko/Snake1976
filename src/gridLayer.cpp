#include <valarray>
#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    mainGrid = new Grid();
}
GridLayer::~GridLayer() {
    mainGrid = nullptr;
}
void GridLayer::Init() {

}
void GridLayer::Update() {

}
void GridLayer::Draw() {

    if(mainGrid != nullptr){
        mainGrid->Draw();
    }
}
void GridLayer::LoadNewGrid(int m_x, int m_y, int m_cellSize){
    mainGrid->Reset(m_x,m_y,m_cellSize);
}