#include <valarray>
#include "Game.h"
#include "GridLayer.h"

GridLayer::GridLayer() {
    renderer = nullptr;
}

GridLayer::~GridLayer(){

}

GridLayer& GridLayer::Instance() {
    static GridLayer gridLayer;
    return gridLayer;
}

void GridLayer::Init()
{
    renderer = WindowLayer::Instance().GetRenderer();
    mainGrid = new Grid(15,20,48,renderer);

}

void GridLayer::Update() {

}

void GridLayer::Draw() {

    mainGrid->DrawGrid();
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





