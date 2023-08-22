#include "SceneManager.h"
#include "Game.h"
#include "Scenes.h"

MenuScene* SceneManager::menuScene;
GameScene* SceneManager::gameScene;
HighScoreScene* SceneManager::highScoreScene;

Scene* SceneManager::currentScene;

SceneManager::SceneManager(){

}
SceneManager& SceneManager::Instance() {
    static SceneManager sceneManager;
    return sceneManager;
}
void SceneManager::Init() {
    menuScene = new MenuScene();
    gameScene = new GameScene();
    highScoreScene = new HighScoreScene();
    currentScene = menuScene;
    currentScene->OnEnter();

}
void SceneManager::GoToHighScore() {
    currentScene->OnExit();
    currentScene = highScoreScene;
    currentScene->OnEnter();
}

void SceneManager::GoToMenu() {
    currentScene->OnExit();
    currentScene = menuScene;
    currentScene->OnEnter();
}

void SceneManager::GoToGame() {
    currentScene->OnExit();
    currentScene = gameScene;
    currentScene->OnEnter();
}

void SceneManager::Update() {
    currentScene->Update();

}

void SceneManager::Draw() {
    currentScene->Draw();
}


