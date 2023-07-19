#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    width = Global::SCREEN::WIDTH ;
    height = Global::SCREEN::HEIGHT;
    cellSize = Global::SCREEN::CELL_SIZE;
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
    for (int x = 0; x < width / Global::SCREEN::CELL_SIZE + 1; ++x) {
        for (int y = 0; y < height / Global::SCREEN::CELL_SIZE + 1; ++y) {
            auto vector = Global::MATH::Vector2D(x * cellSize, y * cellSize);
            cells.push_back(vector);
            SDL_SetRenderDrawColor(renderer, 255,255, 255, 225);
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
    SDL_Rect topBorder = { 0, 0, Global::SCREEN::WIDTH, Global::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &topBorder);

    // Bottom border
    SDL_Rect bottomBorder = { 0, Global::SCREEN::HEIGHT - Global::SCREEN::BORDER_SIZE, Global::SCREEN::WIDTH, Global::SCREEN::BORDER_SIZE};
    SDL_RenderFillRect(renderer, &bottomBorder);

    // Left border
    SDL_Rect leftBorder = { 0, Global::SCREEN::BORDER_SIZE, Global::SCREEN::BORDER_SIZE, Global::SCREEN::HEIGHT - 2 * Global::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &leftBorder);

    // Right border
    SDL_Rect rightBorder = { Global::SCREEN::WIDTH - Global::SCREEN::BORDER_SIZE, Global::SCREEN::BORDER_SIZE, Global::SCREEN::BORDER_SIZE, Global::SCREEN::HEIGHT - 2 * Global::SCREEN::BORDER_SIZE };
    SDL_RenderFillRect(renderer, &rightBorder);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}