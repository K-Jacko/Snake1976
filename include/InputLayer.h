#pragma once
#include "Game.h"
#include "Global.h"

class InputLayer
{
public:
    InputLayer();
    void Init(SDL_Event* m_event);
    void Update();
    Global::Game::Direction InputDirection();
    void SetInputDirection(Global::Game::Direction m_Direction);
private:
    Global::Game::Direction inputDirection;
    SDL_Event* event;
};