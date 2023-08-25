#include "Grid.h"
#include "InputLayer.h"
#include "WindowLayer.h"

Grid::Grid() {
    renderer = WindowLayer::Instance().GetRenderer();
    cellSize = GLOBAL::SCREEN::CELL_SIZE;
}
Grid::~Grid() {
    cells.clear();
    cells.shrink_to_fit();
}
void Grid::CreateGrid() {

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
void Grid::Update() {

}
void Grid::Draw() {
    if(cells.size() > 1){
        for(Cell* cell:cells){
            DrawCell(cell);
        }
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
void Grid::FillCell(Cell* cell){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 225);
    SDL_Rect rc;
    rc.x = cell->position.x;
    rc.y = cell->position.y;
    rc.w = cellSize ;
    rc.h = cellSize;
    SDL_RenderFillRect(renderer, &rc);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Grid::DrawCell(Cell *cell) {
    SDL_SetRenderDrawColor(renderer, 155, 155, 155, 225);
    SDL_Rect rc;
    rc.x = cell->position.x;
    rc.y = cell->position.y;
    rc.w = cellSize ;
    rc.h = cellSize;
    SDL_RenderDrawRect(renderer, &rc);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if(InputLayer::Instance().LeftIsPressed())
    {
        FillCell(FindCell(GLOBAL::MATH::Vector2D(InputLayer::Instance().GetMousePosition().x,InputLayer::Instance().GetMousePosition().y)));
    }
}
void Grid::Reset(int m_W, int m_H, int m_cellSize){
    cells.clear();
    cells.shrink_to_fit();
    width = m_W;
    height = m_H;
    cellSize = m_cellSize;
    CreateGrid();
}
Cell* Grid::FindCell(GLOBAL::MATH::Vector2D m_position) {

    int x = m_position.x;
    int y = m_position.y;

    if (x >= offSetX && x < offSetX + width * cellSize &&
        y >= offSetY && y < offSetY + height * cellSize) {

        int gridX = (x - offSetX) / cellSize;
        int gridY = (y - offSetY) / cellSize;

        for (auto &cell : cells) {
            if (cell->position.x == offSetX + gridX * cellSize && cell->position.y == offSetY + gridY * cellSize) {
                return cell;
            }
        }

    }

    return new Cell(GLOBAL::SCREEN::SCREEN_WIDTH,GLOBAL::SCREEN::SCREEN_HEIGHT);
}

int Grid::GetCellSize() {
    return cellSize;
}

Cell::Cell(){
    position = {0,0};
}

Cell::Cell(int m_x, int m_y) {
    position.x = m_x;
    position.y = m_y;
}
