#pragma once
#include "Game.h"
#include "./snake1976/Snake.h"
#include "layers/AudioLayer.h"

struct MenuScene : public GLOBAL::GAME::Scene  {
    MenuScene() = default;
    void OnEnter() override{
        if(!isInitialized) {
            Init();
        }else {
            UILayer::Instance().GetTextButtons()[0]->SetActive(true);
            UILayer::Instance().GetTextButtons()[1]->SetActive(true);
            UILayer::Instance().GetTextButtons()[2]->SetActive(true);
            UILayer::Instance().GetText()[0]->SetActive(true);
        }
        GridLayer::Instance().LoadNewGrid(15,20,48);
    }
    void Init() override {
        SetUpButtons();
        SetUpTexts();
        SetUpAudio();
        isInitialized = true;
    }
    void SetUpButtons(){
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f, GLOBAL::UI::ButtonSize::Medium , "Start", GLOBAL::SCREEN::FONT_SIZE::MEDIUM,0, "assets/audio/menu-start-haptic.wav");
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f + 100, GLOBAL::UI::ButtonSize::Small,"> HighScores", GLOBAL::SCREEN::FONT_SIZE::SMALL,1, "assets/audio/menu-haptic.wav");
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH - 25, 25, GLOBAL::UI::ButtonSize::Tiny , "X", GLOBAL::SCREEN::FONT_SIZE::SMALL,101, "assets/audio/menu-haptic.wav");

        UILayer::Instance().CreateTextButtons(textButtonData);
    }
    void SetUpTexts(){
        std::vector<GLOBAL::UI::TextData> textData;
        textData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.33, "Snake", GLOBAL::SCREEN::FONT_SIZE::LARGE);
        UILayer::Instance().CreateText(textData);
    }
    void SetUpAudio(){
        AudioLayer::Instance().GetSoundMixer()->LoadMusic("assets/audio/song.wav");
        AudioLayer::Instance().GetSoundMixer()->SetMusicVolume(25);
        AudioLayer::Instance().GetSoundMixer()->PlayMusic(0);
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

struct GameScene : public GLOBAL::GAME::Scene {
    GameScene() = default;
    Snake* snake{};
    void OnEnter() override{
        if(!isInitialized){
            Init();
        }
        UILayer::Instance().GetTextButtons()[2]->SetActive(true);
        UILayer::Instance().GetTextButtons()[3]->SetActive(true);
        UILayer::Instance().GetText()[1]->SetActive(true);
        GridLayer::Instance().LoadNewGrid(15,20,48);
        if(snake == nullptr){
            snake = new Snake();
        }else{
            snake->Reset();
        }
        AudioLayer::Instance().GetSoundMixer()->StopMusic();
        AudioLayer::Instance().GetSoundMixer()->PlayMusic(0);
    }
    void Init() override{
        SetUpButtons();
        SetUpTexts();
        isInitialized = true;
    }
    void SetUpButtons(){
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        if(UILayer::Instance().GetTextButtons().size() < 4){
            textButtonData.emplace_back(25, 25, GLOBAL::UI::ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL,2, "assets/audio/menu-haptic.wav");
        }
        UILayer::Instance().CreateTextButtons(textButtonData);
    }
    void SetUpTexts(){
        std::vector<GLOBAL::UI::TextData> textData;
        textData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.10, "0", GLOBAL::SCREEN::FONT_SIZE::LARGE);
        UILayer::Instance().CreateText(textData);
    }
    void Update() override{
        snake->Update();
        GridLayer::Instance().Update();
        UILayer::Instance().Update();
    }
    void Draw() override{
        snake->Draw();
        GridLayer::Instance().Draw();
        UILayer::Instance().Draw();
    }
    void OnExit() override{
        UILayer::Instance().GetTextButtons()[2]->SetActive(false);
        UILayer::Instance().GetTextButtons()[3]->SetActive(false);
        UILayer::Instance().GetText()[1]->SetActive(false);
    }
};

struct HighScoreScene : public GLOBAL::GAME::Scene{
    HighScoreScene() = default;
    void OnEnter() override{
        if(!isInitialized){
            Init();
        }else{
            UILayer::Instance().GetTextButtons()[2]->SetActive(true);
            UILayer::Instance().GetTextButtons()[3]->SetActive(true);
        }
        GridLayer::Instance().LoadNewGrid(15,10,48);
    }
    void Init() override{
        if(UILayer::Instance().GetTextButtons().size() < 4){
            SetUpButtons();
        }
        UILayer::Instance().GetTextButtons()[2]->SetActive(true);
        UILayer::Instance().GetTextButtons()[3]->SetActive(true);
        isInitialized = true;

    }
    void SetUpButtons(){
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        textButtonData.emplace_back(25, 25, GLOBAL::UI::ButtonSize::Tiny,"<", GLOBAL::SCREEN::FONT_SIZE::SMALL,2, "assets/audio/menu-haptic.wav");
        UILayer::Instance().CreateTextButtons(textButtonData);
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

struct GameOverScene : public GLOBAL::GAME::Scene{
    GameOverScene() = default;

    void OnEnter() override {
        if(!isInitialized){
            Init();
        }
        UILayer::Instance().GetTextButtons()[1]->SetActive(true);
        UILayer::Instance().GetTextButtons()[2]->SetActive(true);
        UILayer::Instance().GetTextButtons()[3]->SetActive(false);
        UILayer::Instance().GetTextButtons()[4]->SetActive(true);
        UILayer::Instance().GetText()[1]->SetActive(true);
        UILayer::Instance().GetText()[2]->SetActive(true);

        GridLayer::Instance().LoadNewGrid(15,20,48);
    }

    void Init() override {
        SetUpButtons();
        SetUpTexts();
        isInitialized = true;
    }
    void SetUpButtons(){
        std::vector<GLOBAL::UI::TextButtonData> textButtonData;
        textButtonData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.77f, GLOBAL::UI::ButtonSize::Small , "Retry", GLOBAL::SCREEN::FONT_SIZE::SMALL,0, "assets/audio/menu-haptic.wav");
        UILayer::Instance().CreateTextButtons(textButtonData);
    }
    void SetUpTexts(){
        std::vector<GLOBAL::UI::TextData> textData;
        textData.emplace_back(GLOBAL::SCREEN::SCREEN_WIDTH / 2, GLOBAL::SCREEN::SCREEN_HEIGHT * 0.33, "GameOver", GLOBAL::SCREEN::FONT_SIZE::MEDIUM);
        UILayer::Instance().CreateText(textData);
    }
    void OnExit() override {
        UILayer::Instance().GetTextButtons()[1]->SetActive(false);
        UILayer::Instance().GetTextButtons()[2]->SetActive(false);
        UILayer::Instance().GetTextButtons()[3]->SetActive(false);
        UILayer::Instance().GetTextButtons()[4]->SetActive(false);
        UILayer::Instance().GetText()[1]->SetActive(false);
        UILayer::Instance().GetText()[2]->SetActive(false);
    }

    void Draw() override {
        if(InputLayer::Instance().LeftIsPressed()){
            GridLayer::Instance().mainGrid->FillCell(GridLayer::Instance().mainGrid->FindCell(GLOBAL::MATH::Vector2D(InputLayer::Instance().GetMousePosition().x,InputLayer::Instance().GetMousePosition().y)),SDL_Color(255,255,255));
        }
        GridLayer::Instance().Draw();
        UILayer::Instance().Draw();
    }

    void Update() override {
        GridLayer::Instance().Update();
        UILayer::Instance().Update();
    }
};