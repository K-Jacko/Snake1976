#pragma once
#include <random>
#include "UILayer.h"
#include "SDL.h"
#include "GridLayer.h"
#include "InputLayer.h"
#include "Timer.h"
#include "SnakeCell.h"
#include "FoodCell.h"

class Snake
{
public:
    Snake(){
        head = new SnakeCell;
        head->cellType = SnakeCellType::HEAD;
        head->position = GLOBAL::MATH::Vector2D(GridLayer::Instance().mainGrid->GetWidth()/2 * GridLayer::Instance().mainGrid->GetCellSize(),GridLayer::Instance().mainGrid->GetHeight()/2 * GridLayer::Instance().mainGrid->GetCellSize());
        cells.push_back(head);

        for (int i = 1; i < snakeLength; ++i) {
            auto tail = new SnakeCell(head->position.x, head->position.y);
            tail->cellType = SnakeCellType::TAIL;
            tail->position = GLOBAL::MATH::Vector2D(head->position.x, head->position.y);
            cells.push_back(tail);
        }
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        foodCell = new FoodCell(GenerateRandomPosition());
    };
    ~Snake(){
        cells.clear();
        cells.shrink_to_fit();
    };
    void Draw(){
        GridLayer::Instance().mainGrid->FillCell(GridLayer::Instance().mainGrid->FindCell(cells[0]->position),SDL_Color(255,255,255));
        GridLayer::Instance().mainGrid->FillCell(GridLayer::Instance().mainGrid->FindCell(foodCell->position), SDL_Color(255,255,255));
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
        if(timer.Elapsed() >= gameSpeed && isStarted){
            for (int i = snakeLength - 1; i > 0; i--) {
                cells[i]->position = cells[i - 1]->position;
            }
            head->position.Add(GetInput());
            CheckPositions();
            timer.Reset();
        }
    };
    void Reset(){
        score = 0;
        gameSpeed = 0.2f;
        snakeLength = 7;
        foodCell->position = GenerateRandomPosition();
        cells.clear();
        cells.shrink_to_fit();
        head->position = {GridLayer::Instance().mainGrid->GetWidth() * GridLayer::Instance().mainGrid->GetCellSize() / 2, GridLayer::Instance().mainGrid->GetHeight() * GridLayer::Instance().mainGrid->GetCellSize() / 2};
        MovementDirection = {0,0};
        isStarted = false;
        cells.push_back(head);
        for (int i = 1; i < snakeLength; ++i) {
            auto tail = new SnakeCell(head->position.x, head->position.y);
            tail->cellType = SnakeCellType::TAIL;
            tail->position = GLOBAL::MATH::Vector2D(head->position.x, head->position.y);
            cells.push_back(tail);
        }
        std::string floatString = std::to_string(score);
        UILayer::Instance().GetText()[1]->ChangeText(floatString.c_str());
        std::cout << cells.size() << std::endl;
    }
private:
    GLOBAL::MATH::Vector2D GetInput(){
        if(!InputLayer::Instance().GetKeyInputs().empty()){
            MovementDirection = GLOBAL::MATH::Vector2D(InputLayer::Instance().GetKeyInputs()[0]->x * GridLayer::Instance().mainGrid->GetCellSize(),InputLayer::Instance().GetKeyInputs()[0]->y * GridLayer::Instance().mainGrid->GetCellSize());
            return {InputLayer::Instance().GetKeyInputs()[0]->x * GridLayer::Instance().mainGrid->GetCellSize(),InputLayer::Instance().GetKeyInputs()[0]->y * GridLayer::Instance().mainGrid->GetCellSize()};

        }else{
            return {MovementDirection};
        }
    };
    GLOBAL::MATH::Vector2D GenerateRandomPosition(){
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> distrX(1, GridLayer::Instance().mainGrid->GetWidth());
      std::uniform_int_distribution<> distrY(1, GridLayer::Instance().mainGrid->GetHeight());
      int randX = distrX(gen) * GridLayer::Instance().mainGrid->GetCellSize();
      int randY = distrY(gen) * GridLayer::Instance().mainGrid->GetCellSize();
      return {randX,randY};
    };
    void CheckPositions(){
        if(foodCell->position == cells[0]->position){
            foodCell->position = GenerateRandomPosition();
            auto tail = new SnakeCell(cells[snakeLength -1]->position.x, cells[snakeLength -1]->position.y);
            tail->cellType = SnakeCellType::TAIL;
            cells.push_back(tail);
            snakeLength += 1;
            IncreaseScore();
        }
        for(SnakeCell* cell : cells){
            if(cell->position.x > GridLayer::Instance().mainGrid->GetWidth() * GridLayer::Instance().mainGrid->GetCellSize()){
                cell->position.x = 0;
            } else if(cell->position.x < GridLayer::Instance().mainGrid->GetCellSize()){
                cell->position.x = GridLayer::Instance().mainGrid->GetWidth() * GridLayer::Instance().mainGrid->GetCellSize();
            }
            if(cell->position.y > (GridLayer::Instance().mainGrid->GetHeight() + 1 ) * GridLayer::Instance().mainGrid->GetCellSize()){
                cell->position.y = 0;
            } else if(cell->position.y < GridLayer::Instance().mainGrid->GetCellSize()){
                cell->position.y = (GridLayer::Instance().mainGrid->GetHeight() + 1 ) * GridLayer::Instance().mainGrid->GetCellSize();
            }
        }
    };
    void IncreaseScore(){
        score += 1;
        if(gameSpeed > 0.15f)
        {
            gameSpeed -= 0.005f;
        }else{
            gameSpeed = 0.15f;
        }
        std::string floatString = std::to_string(score);
        UILayer::Instance().GetText()[1]->ChangeText(floatString.c_str());
    }
    GLOBAL::MATH::Vector2D MovementDirection{0,-1};
    FoodCell* foodCell;
    SnakeCell* head;
    bool isStarted = false;
    Timer timer;
    int snakeLength = 7;
    int score = 0;
    float gameSpeed = 0.2f;
    std::vector<SnakeCell*> cells;
};

