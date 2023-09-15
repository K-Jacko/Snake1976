#pragma once
#include "SceneManager.h"
#include "WindowLayer.h"
#include "UILayer.h"
#include "GridLayer.h"


struct MenuScene;
struct GameScene;
struct HighScoreScene;
struct Scene;

class SceneManager
{
public:
    static SceneManager& Instance();
    SceneManager();
    void Init();
    void Update();
    void Draw();
    static void GoToHighScore();
    static void GoToMenu();
    static void GoToGame();
    static Scene* currentScene;
    static MenuScene menuScene;
    static GameScene gameScene;
    static HighScoreScene highScoreScene;
};