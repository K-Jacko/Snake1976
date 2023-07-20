#pragma once
#include "Global.h"

class InputLayer
{
public:
    InputLayer();
    ~InputLayer();
    static InputLayer& Instance();
    void Init(SDL_Event* m_event);
    void Update();
    void Reset();
    std::vector<GLOBAL::MATH::Vector2D*> GetKeyInputs(){return keyInputs;}
    bool RightIsPressed();
    bool LeftIsPressed();
    std::vector<int> GetMouseInputs(){return mouseInputs;}
    GLOBAL::MATH::Vector2D GetMousePosition();
private:
    void AddInput(int m_mouseInput);
    void AddInput(GLOBAL::GAME::Direction m_Direction);
    void RemoveMouseInput(int m_mouseInput);
    void RemoveKeyInput(GLOBAL::GAME::Direction m_direction);
    static bool matchesTarget(int _i, int _j);
    static bool matchesTarget(GLOBAL::MATH::Vector2D v, GLOBAL::MATH::Vector2D t);
    bool isPressedLeft, isPressedRight;
    std::vector<GLOBAL::MATH::Vector2D*> keyInputs;
    std::vector<int> mouseInputs;
    GLOBAL::MATH::Vector2D mousePosition;
    SDL_Event* event;
};