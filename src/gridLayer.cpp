#include <valarray>
#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    renderer = nullptr;
    mainGrid = nullptr;
}

GridLayer::~GridLayer(){
    renderer = nullptr;
    mainGrid = nullptr;
}
GridLayer& GridLayer::Instance() {
    static GridLayer gridLayer;
    return gridLayer;
}
void GridLayer::Init()
{
    renderer = WindowLayer::Instance().GetRenderer();
}
void GridLayer::Update() {

}
void GridLayer::Draw() {

    if(mainGrid != nullptr){
        mainGrid->DrawGrid();
    }
    // Top border
    SDL_Rect topBorder = {0, 0, GLOBAL::SCREEN::SCREEN_WIDTH, GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &topBorder);

    // Bottom border
    SDL_Rect bottomBorder = {0, GLOBAL::SCREEN::SCREEN_HEIGHT - GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::SCREEN_WIDTH, GLOBAL::SCREEN::BORDER_SIZE};
    SDL_RenderFillRect(renderer, &bottomBorder);

    // Left border
    SDL_Rect leftBorder = {0, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::SCREEN_HEIGHT - 2 * GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &leftBorder);

    // Right border
    SDL_Rect rightBorder = {GLOBAL::SCREEN::SCREEN_WIDTH - GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::SCREEN_HEIGHT - 2 * GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &rightBorder);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
void GridLayer::Reset() {
    delete mainGrid;
}
void GridLayer::LoadNewGrid(int m_x, int m_y, int m_cellSize){
    Reset();
    mainGrid = new Grid(m_x,m_y,m_cellSize,renderer);
}