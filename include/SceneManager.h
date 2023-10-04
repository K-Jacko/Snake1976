#pragma once
#include "SceneManager.h"
#include "WindowLayer.h"
#include "UILayer.h"
#include "GridLayer.h"


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
    static void GoToGameOver();
    static struct Scene* currentScene;
    static struct MenuScene menuScene;
    static struct GameScene gameScene;
    static struct HighScoreScene highScoreScene;
    static struct GameOverScene gameOverScene;
};