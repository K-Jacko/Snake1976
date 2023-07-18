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
    SceneManager();
    void ChangeScene();
    void LoadScene();
    void Init();
};