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
    bool isInitialized;
};

struct MenuScene : public Scene  {
    MenuScene() = default;
    void OnEnter() override{
        if(!isInitialized) {
            Init();
        }else {
            UILayer::Instance().GetTextButtons()[0]->SetActive(true);
            UILayer::Instance().GetTextButtons()[1]->SetActive(true);
            UILayer::Instance().GetText()[0]->SetActive(true);
        }
        GridLayer::Instance().LoadNewGrid(15,20,48);
    }
    void Init() override {
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f, GLOBAL::UI::ButtonSize::Medium , "Start", GLOBAL::SCREEN::FONT_SIZE::MEDIUM);
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f + 100, GLOBAL::UI::ButtonSize::Small,"> HighScores", GLOBAL::SCREEN::FONT_SIZE::SMALL);
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH - 25, 25, GLOBAL::UI::ButtonSize::Tiny , "X", GLOBAL::SCREEN::FONT_SIZE::SMALL);
        textButtonData.emplace_back(25, 25, GLOBAL::UI::ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL);
        UILayer::Instance().CreateTextButtons(textButtonData);
        std::vector<GLOBAL::UI::TextData> textData;
        textData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.33, "Snake", GLOBAL::SCREEN::FONT_SIZE::LARGE);
        UILayer::Instance().CreateText(textData);
        UILayer::Instance().GetTextButtons()[0]->SetAction(SceneManager::GoToGame);
        UILayer::Instance().GetTextButtons()[1]->SetAction(SceneManager::GoToHighScore);
        UILayer::Instance().GetTextButtons()[2]->SetActive(false);
        UILayer::Instance().GetTextButtons()[3]->SetActive(false);

        isInitialized = true;
    }
    void Update() override{
        GridLayer::Instance().Update();
        UILayer::Instance().Update();
    }
    void Draw() override{
        GridLayer::Instance().Draw();
        UILayer::Instance().Draw();
    }
    void OnExit() override{
        UILayer::Instance().GetTextButtons()[0]->SetActive(false);
        UILayer::Instance().GetTextButtons()[1]->SetActive(false);
        UILayer::Instance().GetText()[0]->SetActive(false);
    }
};

struct GameScene : public Scene {
    GameScene() = default;
    Snake* snake{};
    void OnEnter() override{

        if(!isInitialized) {
            Init();
        }else {
            UILayer::Instance().GetTextButtons()[2]->SetActive(true);
            UILayer::Instance().GetTextButtons()[3]->SetActive(true);
            UILayer::Instance().GetText()[1]->SetActive(true);
            if(snake == nullptr){
                snake = new Snake();
            }else{
                snake->Reset();
            }
            isInitialized = true;
        }
        GridLayer::Instance().LoadNewGrid(30,40,24);
    }
    void Init() override{
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        std::vector<GLOBAL::UI::TextData> textData;
        textData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.10, "0", GLOBAL::SCREEN::FONT_SIZE::LARGE);
        UILayer::Instance().CreateText(textData);
        UILayer::Instance().CreateTextButtons(textButtonData);
        UILayer::Instance().GetTextButtons()[2]->SetAction(Game::End);
        UILayer::Instance().GetTextButtons()[3]->SetAction(SceneManager::GoToMenu);
        UILayer::Instance().GetTextButtons()[2]->SetActive(true);
        UILayer::Instance().GetTextButtons()[3]->SetActive(true);
        snake = new Snake();
        isInitialized = true;
    }
    void Update() override{
        GridLayer::Instance().Update();
        snake->Update();
        UILayer::Instance().Update();
    }
    void Draw() override{
        GridLayer::Instance().Draw();
        snake->Draw();
        UILayer::Instance().Draw();
    }
    void OnExit() override{
        UILayer::Instance().GetTextButtons()[2]->SetActive(false);
        UILayer::Instance().GetTextButtons()[3]->SetActive(false);
        UILayer::Instance().GetText()[1]->SetActive(false);
    }
};

struct HighScoreScene : public Scene{
    HighScoreScene() = default;
    void OnEnter() override{

        if(!isInitialized && !UILayer::Instance().GetTextButtons()[2] && !UILayer::Instance().GetTextButtons()[3]){
            Init();
        }
        else{
            UILayer::Instance().GetTextButtons()[2]->SetActive(true);
            UILayer::Instance().GetTextButtons()[3]->SetActive(true);
            isInitialized = true;
        }
        GridLayer::Instance().LoadNewGrid(15,10,48);
    }
    void Init() override{
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH - 25, 25, GLOBAL::UI::ButtonSize::Tiny , "X", GLOBAL::SCREEN::FONT_SIZE::SMALL);
        textButtonData.emplace_back(25, 25, GLOBAL::UI::ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL);
        UILayer::Instance().CreateTextButtons(textButtonData);
        UILayer::Instance().GetTextButtons()[2]->SetAction(Game::End);
        UILayer::Instance().GetTextButtons()[3]->SetAction(SceneManager::GoToMenu);
        isInitialized = true;
    }
    void Update() override{
        GridLayer::Instance().Update();
        UILayer::Instance().Update();

    }
    void Draw() override{
        GridLayer::Instance().Draw();
        UILayer::Instance().Draw();

    }
    void OnExit() override{
        UILayer::Instance().GetTextButtons()[2]->SetActive(false);
        UILayer::Instance().GetTextButtons()[3]->SetActive(false);
    }
};