#pragma once
#include "Global.h"
#include "Grid.h"

class GridLayer : public ILayer{
public:
    GridLayer(){
        mainGrid = new Grid(0,0,0);
    };
    ~GridLayer() = default;
    static GridLayer& Instance(){
        static GridLayer instance;
        return instance;
    };
    void Init() override{}
    void Update() override{}
    void Draw() override{mainGrid->Draw();};
    void LoadNewGrid(int m_x, int m_y, int m_cellSize){
        delete(mainGrid);
        mainGrid = new Grid(m_x,m_y,m_cellSize);};
    Grid* mainGrid;
private:
    SDL_Renderer* renderer = nullptr;
};