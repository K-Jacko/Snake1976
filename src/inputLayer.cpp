#include "InputLayer.h"

InputLayer::InputLayer(){
    event = nullptr;
    inputDirection = Global::GAME::Direction::NONE;
}
void InputLayer::Init(SDL_Event* m_event) {
    event = m_event;
}
void InputLayer::Update() {
    if(event->type== SDL_KEYDOWN){
        switch (event->key.keysym.sym) {
            case SDLK_w:
                AddInput(Global::GAME::Direction::UP);
                break;
            case SDLK_a:
                AddInput(Global::GAME::Direction::LEFT);
                break;
            case SDLK_s:
                AddInput(Global::GAME::Direction::DOWN);
                break;
            case SDLK_d:
                AddInput(Global::GAME::Direction::RIGHT);
                break;
        }
    }
    if(event->type == SDL_KEYUP){
        switch (event->key.keysym.sym) {
            case SDLK_w:
                RemoveKeyInput(Global::GAME::Direction::UP);
                break;
            case SDLK_a:
                RemoveKeyInput(Global::GAME::Direction::LEFT);
                break;
            case SDLK_s:
                RemoveKeyInput(Global::GAME::Direction::DOWN);
                break;
            case SDLK_d:
                RemoveKeyInput(Global::GAME::Direction::RIGHT);
                break;
        }
    }
}
Global::GAME::Direction InputLayer::InputDirection() {
    return inputDirection;
}
void InputLayer::AddInput(Global::GAME::Direction m_Direction) {
    auto vector = new Global::MATH::Vector2D(m_Direction);
    if(keyInputs.size() < 2)
    {
        keyInputs.push_back(vector);
        if(Global::DEBUG)
        {
            Global::MATH::Vector2D vec;
            vec = *vector;
            std::cout << vec << std::endl;
        }
    }
}

void InputLayer::RemoveMouseInput(int _i)
{
    auto input = _i;
    mouseInputs.erase(std::remove_if(mouseInputs.begin(), mouseInputs.end(), [&](int v) {return matchesTarget(v,input);}), mouseInputs.end());

}
void InputLayer::RemoveKeyInput(Global::GAME::Direction direction)
{
    auto vector = new Global::MATH::Vector2D(direction);
    keyInputs.erase(std::remove_if(keyInputs.begin(), keyInputs.end(), [&](Global::MATH::Vector2D* v) {return matchesTarget(*v, *vector);}), keyInputs.end());
}
bool InputLayer::matchesTarget(int _i, int _j)
{
    return _i == _j;
}
bool InputLayer::matchesTarget(Global::MATH::Vector2D v, Global::MATH::Vector2D t)
{
    return v.x == t.x && v.y == t.y;
}