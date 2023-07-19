#pragma once
#include "Global.h"

class InputLayer
{
public:
    InputLayer();
    ~InputLayer();
    InputLayer& Instance();
    void Init(SDL_Event* m_event);
    void Update();
    Global::GAME::Direction InputDirection();
    void AddInput(int m_mouseInput);
    void AddInput(Global::GAME::Direction m_Direction);
    void RemoveMouseInput(int m_mouseInput);
    void RemoveKeyInput(Global::GAME::Direction m_direction);
    std::vector<Global::MATH::Vector2D*> GetKeyInputs(){return keyInputs;}
    bool RightIsPressed();
    bool LeftIsPressed();
    std::vector<int> GetMouseInputs(){return mouseInputs;}
    Global::MATH::Vector2D* GetMousePosition();
private:
    bool isPressedLeft, isPressedRight;
    Global::GAME::Direction inputDirection;
    std::vector<Global::MATH::Vector2D*> keyInputs;
    std::vector<int> mouseInputs;
    Global::MATH::Vector2D mousePosition;
    SDL_Event* event;
    static bool matchesTarget(int _i, int _j);
    static bool matchesTarget(Global::MATH::Vector2D v, Global::MATH::Vector2D t);
};