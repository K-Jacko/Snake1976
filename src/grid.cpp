#include "Grid.h"
#include "InputLayer.h"

Grid::Grid(int m_W, int m_H, int m_cellSize, SDL_Renderer* m_renderer){
    renderer = m_renderer;
    width = m_W;
    height = m_H;
    cellSize = m_cellSize;
    CreateGrid();
}
Grid::~Grid() {
    cells.clear();
    cells.shrink_to_fit();
}
void Grid::CreateGrid(){

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
void Grid::Update()
{

}
void Grid::DrawGrid() {
    for(Cell* cell:cells)
    {
        DrawCell(cell);
    }
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
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 225);
    SDL_Rect rc;
    rc.x = cell->position.x;
    rc.y = cell->position.y;
    rc.w = cellSize ;
    rc.h = cellSize;
    SDL_RenderDrawRect(renderer, &rc);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if(InputLayer::Instance().LeftIsPressed())
    {
        FillCell(FindCell());
    }
}
Cell* Grid::FindCell() {

    int mouseX = InputLayer::Instance().GetMousePosition().x;
    int mouseY = InputLayer::Instance().GetMousePosition().y;

    if (mouseX >= offSetX && mouseX < offSetX + width * cellSize &&
        mouseY >= offSetY && mouseY < offSetY + height * cellSize) {

        int gridX = (mouseX - offSetX) / cellSize;
        int gridY = (mouseY - offSetY) / cellSize;

        for (auto &cell : cells) {
            if (cell->position.x == offSetX + gridX * cellSize && cell->position.y == offSetY + gridY * cellSize) {
                return cell;
            }
        }

    }

    return new Cell(GLOBAL::SCREEN::SCREEN_WIDTH,GLOBAL::SCREEN::SCREEN_HEIGHT);
}

Cell::Cell(int m_x, int m_y) {
    position.x = m_x;
    position.y = m_y;
}
