#pragma once
#include "SceneManager.h"
#include "Game.h"

struct Scene
{
    Scene() = default;
    virtual void OnEnter(){}
    virtual void OnExit(){}
    virtual void Draw(){}
    virtual void Update(){}
    virtual void Init(){}
    virtual void Refresh(){}
    UILayer* uILayer;
    GridLayer* gridLayer;
};

struct MenuScene : public Scene  {
    MenuScene() = default;
    void OnEnter() override{
        if(!uILayer){
            uILayer = new UILayer();
            std::vector<GLOBAL::UI::TextButtonData> textButtonData;
            textButtonData.push_back(GLOBAL::UI::TextButtonData(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f, GLOBAL::UI::ButtonSize::Medium , "Start", GLOBAL::SCREEN::FONT_SIZE::MEDIUM));
            textButtonData.push_back(GLOBAL::UI::TextButtonData(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f + 100, GLOBAL::UI::ButtonSize::Small,"> HighScores", GLOBAL::SCREEN::FONT_SIZE::SMALL));
            uILayer->CreateTextButtons(textButtonData);
            uILayer->GetTextButtons()[0]->SetAction(SceneManager::GoToGame);
            uILayer->GetTextButtons()[1]->SetAction(SceneManager::GoToHighScore);
        }else{
            uILayer->GetTextButtons()[0]->SetActive(true);
            uILayer->GetTextButtons()[1]->SetActive(true);
        }
        if(!gridLayer){
            gridLayer = new GridLayer();
            gridLayer->LoadNewGrid(15,20,48);
        }

    }
    void Update() override{
        gridLayer->Update();
        uILayer->Update();

    }
    void Draw() override{
        gridLayer->Draw();
        uILayer->Draw();

    }
    void OnExit() override{
        uILayer->GetTextButtons()[0]->SetActive(false);
        uILayer->GetTextButtons()[1]->SetActive(false);
    }
};

struct GameScene : public Scene {
    GameScene() = default;
    void OnEnter() override{
        if(!uILayer){
            uILayer = new UILayer();
            if(uILayer->GetTextButtons().size() < 4){
                std::vector<GLOBAL::UI::TextButtonData> textButtonData;
                textButtonData.push_back(GLOBAL::UI::TextButtonData(GLOBAL::SCREEN::SCREEN_WIDTH - 25, 25, GLOBAL::UI::ButtonSize::Tiny , "X", GLOBAL::SCREEN::FONT_SIZE::SMALL));
                textButtonData.push_back(GLOBAL::UI::TextButtonData(25, 25, GLOBAL::UI::ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL));
                uILayer->CreateTextButtons(textButtonData);
                uILayer->GetTextButtons()[2]->SetAction(Game::End);
                uILayer->GetTextButtons()[3]->SetAction(SceneManager::GoToMenu);
            }
            else{
                uILayer->GetTextButtons()[2]->SetActive(true);
                uILayer->GetTextButtons()[3]->SetActive(true);
            }
        }
        else{
            uILayer->GetTextButtons()[2]->SetActive(true);
            uILayer->GetTextButtons()[3]->SetActive(true);
        }
        if(!gridLayer){
            gridLayer = new GridLayer();
            gridLayer->LoadNewGrid(30,40,24);
        }
        snake = new Snake(gridLayer->mainGrid);
    }
    Snake* snake;
    void Update() override{
        gridLayer->Update();
        uILayer->Update();
        snake->Update();

    }
    void Draw() override{
        gridLayer->Draw();
        uILayer->Draw();
        snake->Draw();

    }
    void OnExit() override{
        uILayer->GetTextButtons()[2]->SetActive(false);
        uILayer->GetTextButtons()[3]->SetActive(false);
    }
};

struct HighScoreScene : public Scene {
    HighScoreScene() = default;
    void OnEnter() override{
        if(!uILayer){
            uILayer = new UILayer();
            if(uILayer->GetTextButtons().size() < 4){
                std::vector<GLOBAL::UI::TextButtonData> textButtonData;
                textButtonData.push_back(GLOBAL::UI::TextButtonData(GLOBAL::SCREEN::SCREEN_WIDTH - 25, 25, GLOBAL::UI::ButtonSize::Tiny , "X", GLOBAL::SCREEN::FONT_SIZE::SMALL));
                textButtonData.push_back(GLOBAL::UI::TextButtonData(25, 25, GLOBAL::UI::ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL));
                uILayer->CreateTextButtons(textButtonData);
                uILayer->GetTextButtons()[2]->SetAction(Game::End);
                uILayer->GetTextButtons()[3]->SetAction(SceneManager::GoToMenu);
            }
            else{
                uILayer->GetTextButtons()[2]->SetActive(true);
                uILayer->GetTextButtons()[3]->SetActive(true);
            }
        }
        else{
            uILayer->GetTextButtons()[2]->SetActive(true);
            uILayer->GetTextButtons()[3]->SetActive(true);
        }
        if(!gridLayer){
            gridLayer = new GridLayer();
            gridLayer->LoadNewGrid(15,10,48);
        }
    }
    void Update() override{
        gridLayer->Update();
        uILayer->Update();

    }
    void Draw() override{
        gridLayer->Draw();
        uILayer->Draw();

    }
    void OnExit() override{
        uILayer->GetTextButtons()[2]->SetActive(false);
        uILayer->GetTextButtons()[3]->SetActive(false);
    }
};