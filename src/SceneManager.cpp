#include "SceneManager.h"
#include "Scenes.h"

MenuScene SceneManager::menuScene;
GameScene SceneManager::gameScene;
HighScoreScene SceneManager::highScoreScene;
GameOverScene SceneManager::gameOverScene;

Scene* SceneManager::currentScene;

SceneManager::SceneManager()= default;

SceneManager& SceneManager::Instance() {
    static SceneManager sceneManager;
    return sceneManager;
}
void SceneManager::Init() {
    auto Grid = new GridLayer();
    auto UI = new UILayer();
    menuScene = MenuScene();
    gameScene = GameScene();
    highScoreScene = HighScoreScene();
    gameOverScene = GameOverScene();

    currentScene = &menuScene;
    currentScene->OnEnter();

}
void SceneManager::GoToHighScore() {
    currentScene->OnExit();
    currentScene = &highScoreScene;
    currentScene->OnEnter();
}

void SceneManager::GoToMenu() {
    currentScene->OnExit();
    currentScene = &menuScene;
    currentScene->OnEnter();
}

void SceneManager::GoToGame() {
    currentScene->OnExit();
    currentScene = &gameScene;
    currentScene->OnEnter();
}

void SceneManager::GoToGameOver() {
    currentScene->OnExit();
    currentScene = &gameOverScene;
    currentScene->OnEnter();
}

void SceneManager::Update() {
    currentScene->Update();

}

void SceneManager::Draw() {
    currentScene->Draw();
}


