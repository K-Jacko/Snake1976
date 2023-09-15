#pragma once
#include "GridLayer.h"
#include "InputLayer.h"
#include "Timer.h"
#include "SnakeCell.h"

class Snake
{
public:
    Snake(){
        auto head = new SnakeCell;
        head->cellType = SnakeCellType::HEAD;
        head->position = GLOBAL::MATH::Vector2D(GLOBAL::SCREEN::SCREEN_WIDTH/2,GLOBAL::SCREEN::SCREEN_HEIGHT/2);
        cells.push_back(head);

        for (int i = 1; i < snakeLength; ++i) {
            auto tail = new SnakeCell(head->position.x, head->position.y);
            tail->cellType = SnakeCellType::TAIL;
            tail->position = GLOBAL::MATH::Vector2D(head->position.x, head->position.y);
            cells.push_back(tail);
        }
    };
    ~Snake(){
        cells.clear();
        cells.shrink_to_fit();
    };
    void Draw(){
        GridLayer::Instance().mainGrid->FillCell(GridLayer::Instance().mainGrid->FindCell(cells[0]->position),SDL_Color(255,255,255));
        for (int i = 1; i < cells.size(); ++i) {
            GridLayer::Instance().mainGrid->FillCell(GridLayer::Instance().mainGrid->FindCell(cells[i]->position),SDL_Color(200,200,200));
        }
        if(InputLayer::Instance().LeftIsPressed()){
            GridLayer::Instance().mainGrid->FillCell(GridLayer::Instance().mainGrid->FindCell(GLOBAL::MATH::Vector2D(InputLayer::Instance().GetMousePosition().x,InputLayer::Instance().GetMousePosition().y)),SDL_Color(255,255,255));
        }
    };
    void Update(){
        if(!InputLayer::Instance().GetKeyInputs().empty()){
            isStarted = true;
        }
        if(timer.Elapsed() >= 0.2 && isStarted){
            for (int i = snakeLength - 1; i > 0; i--) {
                cells[i]->position = cells[i - 1]->position;
            }
            cells[0]->position.Add(GetInput());

            timer.Reset();
        }
    };
private:
    GLOBAL::MATH::Vector2D GetInput(){
        if(!InputLayer::Instance().GetKeyInputs().empty()){
            MovementDirection = GLOBAL::MATH::Vector2D(InputLayer::Instance().GetKeyInputs()[0]->x * GridLayer::Instance().mainGrid->GetCellSize(),InputLayer::Instance().GetKeyInputs()[0]->y * GridLayer::Instance().mainGrid->GetCellSize());
            return {InputLayer::Instance().GetKeyInputs()[0]->x * GridLayer::Instance().mainGrid->GetCellSize(),InputLayer::Instance().GetKeyInputs()[0]->y * GridLayer::Instance().mainGrid->GetCellSize()};

        }else{
            return {MovementDirection};
        }
    };
    GLOBAL::MATH::Vector2D MovementDirection{0,-1};
    bool isStarted = false;
    Timer timer;
    int snakeLength = 7;
    std::vector<SnakeCell*> cells;

};

