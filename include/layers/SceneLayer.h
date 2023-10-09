#pragma once
#include "EventLayer.h"
#include "Scenes.h"
#include "Global.h"

class SceneLayer : public ILayer
{
public:
    static SceneLayer& Instance(){
        static SceneLayer sceneManager;
        return sceneManager;
    };
    SceneLayer(){
        menuScene = MenuScene();
        gameScene = GameScene();
        highScoreScene = HighScoreScene();
        gameOverScene = GameOverScene();

        currentScene = &menuScene;
        currentScene->OnEnter();
    };
    void Init() override{

    };
    void Update() override{
        if(EventLayer::Instance().GetEvent().type == SDL_USEREVENT){
            switch (EventLayer::Instance().GetEvent().user.code) {
                case 0:
                    GoToGame();
                    break;
                case 1:
                    GoToHighScore();
                    break;
                case 2:
                    GoToMenu();
                    break;
                case 3:
                    GoToGameOver();
                    break;
            }
        }
        currentScene->Update();

    };
    void Draw() override{
        currentScene->Draw();
    };
    static void GoToHighScore(){
        currentScene->OnExit();
        currentScene = &highScoreScene;
        currentScene->OnEnter();
    };
    static void GoToMenu(){
        currentScene->OnExit();
        currentScene = &menuScene;
        currentScene->OnEnter();
    };
    static void GoToGame(){
        currentScene->OnExit();
        currentScene = &gameScene;
        currentScene->OnEnter();
    };
    static void GoToGameOver(){
        currentScene->OnExit();
        currentScene = &gameOverScene;
        currentScene->OnEnter();
    };
    static GLOBAL::GAME::Scene* currentScene;
    static MenuScene menuScene;
    static GameScene gameScene;
    static HighScoreScene highScoreScene;
    static GameOverScene gameOverScene;
};