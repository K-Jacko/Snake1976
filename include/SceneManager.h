#pragma once
#include "SceneManager.h"
#include "WindowLayer.h"

struct Scene
{
    Scene();
    void OnEnter();
    void OnExit();
private:




};

class SceneManager
{
public:
    static SceneManager& Instance();
    SceneManager();
    void ChangeScene();
    void LoadScene();
    void Init();
    Scene currentScene;
};