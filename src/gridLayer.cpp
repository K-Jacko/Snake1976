#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    width = GLOBAL::SCREEN::WIDTH ;
    height = GLOBAL::SCREEN::HEIGHT;
    cellSize = GLOBAL::SCREEN::CELL_SIZE;
    renderer = nullptr;
}

GridLayer& GridLayer::Instance() {
    static GridLayer gridLayer;
    return gridLayer;
}

void GridLayer::Init(SDL_Renderer* m_renderer)
{
    renderer = m_renderer;
}

void GridLayer::Update() {

}

void GridLayer::Draw() {
    for (int x = 0; x < width / GLOBAL::SCREEN::CELL_SIZE + 1; ++x) {
        for (int y = 0; y < height / GLOBAL::SCREEN::CELL_SIZE + 1; ++y) {
            auto vector = GLOBAL::MATH::Vector2D(x * cellSize, y * cellSize);
            cells.push_back(vector);
            SDL_SetRenderDrawColor(renderer, 100,100, 100, 225);
            SDL_Rect rc;
            rc.x = x * cellSize;
            rc.y = y * cellSize;
            rc.w = cellSize ;
            rc.h = cellSize;
            SDL_RenderDrawRect(renderer, &rc);
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Top border
    SDL_Rect topBorder = {0, 0, GLOBAL::SCREEN::WIDTH, GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &topBorder);

    // Bottom border
    SDL_Rect bottomBorder = {0, GLOBAL::SCREEN::HEIGHT - GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::WIDTH, GLOBAL::SCREEN::BORDER_SIZE};
    SDL_RenderFillRect(renderer, &bottomBorder);

    // Left border
    SDL_Rect leftBorder = {0, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::HEIGHT - 2 * GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &leftBorder);

    // Right border
    SDL_Rect rightBorder = {GLOBAL::SCREEN::WIDTH - GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::BORDER_SIZE, GLOBAL::SCREEN::HEIGHT - 2 * GLOBAL::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &rightBorder);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}