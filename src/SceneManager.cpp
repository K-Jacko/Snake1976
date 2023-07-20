#include "SceneManager.h"
#include "Game.h"

Scene::Scene(){

}

void Scene::OnEnter() {

}
void Scene::OnExit() {

}

SceneManager::SceneManager(){
}
SceneManager& SceneManager::Instance() {
    static SceneManager sceneManager;
    return sceneManager;
}
void SceneManager::Init() {

}
void SceneManager::ChangeScene() {

}
void SceneManager::LoadScene() {

}