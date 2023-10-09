#include "Grid.h"
#include "./layers/InputLayer.h"
#include "./layers/WindowLayer.h"

Grid::Grid(int m_W, int m_H, int m_cellSize) {
    renderer = WindowLayer::Instance().GetRenderer();
    cellSize = GLOBAL::SCREEN::CELL_SIZE;
    width = m_W;
    height = m_H;
    cellSize = m_cellSize;
    int pixelsX = width * cellSize;
    int pixelsY = height * cellSize;
    offSetX = (GLOBAL::SCREEN::SCREEN_WIDTH - pixelsX) / 2;
    offSetY = (GLOBAL::SCREEN::SCREEN_HEIGHT - pixelsY) / 2;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            auto cell = new Cell(offSetX + x * cellSize, offSetY + y * cellSize);
            cells.push_back(cell);
        }
    }
}
Grid::~Grid() {
    cells.clear();
    cells.shrink_to_fit();
}
void Grid::Update() {

}
void Grid::Draw() {
    for(Cell* cell:cells){
        SDL_SetRenderDrawColor(renderer, 155, 155, 155, 225);
        SDL_Rect rc;
        rc.x = cell->position.x;
        rc.y = cell->position.y;
        rc.w = cellSize ;
        rc.h = cellSize;
        SDL_RenderDrawRect(renderer, &rc);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    SDL_Rect topBorder = {0, 0, GLOBAL::SCREEN::SCREEN_WIDTH, GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &topBorder);

    SDL_Rect bottomBorder = {0, GLOBAL::SCREEN::SCREEN_HEIGHT - GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::SCREEN_WIDTH, GLOBAL::SCREEN::BORDER_SIZE};
    SDL_RenderFillRect(renderer, &bottomBorder);

    SDL_Rect leftBorder = {0, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::SCREEN_HEIGHT - 2 * GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &leftBorder);

    SDL_Rect rightBorder = {GLOBAL::SCREEN::SCREEN_WIDTH - GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::SCREEN_HEIGHT - 2 * GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &rightBorder);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
void Grid::FillCell(Cell *cell, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    SDL_Rect rc;
    rc.x = cell->position.x;
    rc.y = cell->position.y;
    rc.w = cellSize ;
    rc.h = cellSize;
    SDL_RenderFillRect(renderer, &rc);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

Cell* Grid::FindCell(GLOBAL::MATH::Vector2D m_position) {

    int x = m_position.x;
    int y = m_position.y;

    int gridX = (x - offSetX) / cellSize;
    int gridY = (y - offSetY) / cellSize;

    for (auto &cell : cells) {
        if (cell->position.x == offSetX + gridX * cellSize && cell->position.y == offSetY + gridY * cellSize) {
            return cell;
        }
    }

    return new Cell(0,0);
}


