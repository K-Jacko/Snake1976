#pragma once

struct Scene
{
    Scene();
    void OnEnter();
    void OnExit();
};

class SceneManager
{
public:
    static SceneManager& Instance();
    SceneManager();
    void ChangeScene();
    void LoadScene();
    void Init();
};