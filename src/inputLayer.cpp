#include "InputLayer.h"

InputLayer::InputLayer(){
    event = nullptr;
    inputDirection = GLOBAL::GAME::Direction::NONE;
    isPressedRight = isPressedLeft = false;
}
InputLayer::~InputLayer(){
    keyInputs.clear();
    keyInputs.shrink_to_fit();
    mouseInputs.clear();
    mouseInputs.shrink_to_fit();
}
InputLayer& InputLayer::Instance() {
    static InputLayer instance;
    return instance;
}
void InputLayer::Init(SDL_Event* m_event) {
    event = m_event;
}
void InputLayer::Update() {
    if(event->type== SDL_KEYDOWN){
        switch (event->key.keysym.sym) {
            case SDLK_w:
                AddInput(GLOBAL::GAME::Direction::UP);
                break;
            case SDLK_a:
                AddInput(GLOBAL::GAME::Direction::LEFT);
                break;
            case SDLK_s:
                AddInput(GLOBAL::GAME::Direction::DOWN);
                break;
            case SDLK_d:
                AddInput(GLOBAL::GAME::Direction::RIGHT);
                break;
        }
    }
    if(event->type == SDL_KEYUP){
        switch (event->key.keysym.sym) {
            case SDLK_w:
                RemoveKeyInput(GLOBAL::GAME::Direction::UP);
                break;
            case SDLK_a:
                RemoveKeyInput(GLOBAL::GAME::Direction::LEFT);
                break;
            case SDLK_s:
                RemoveKeyInput(GLOBAL::GAME::Direction::DOWN);
                break;
            case SDLK_d:
                RemoveKeyInput(GLOBAL::GAME::Direction::RIGHT);
                break;
        }
    }
    switch (event->type) {
        case SDL_MOUSEBUTTONDOWN:
            if(event->button.button == SDL_BUTTON_LEFT)
            {
                AddInput(1);
                isPressedLeft = true;

            }
            if(event->button.button == SDL_BUTTON_RIGHT)
            {
                AddInput(2);
                isPressedRight = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if(event->button.button == SDL_BUTTON_LEFT)
            {
                RemoveMouseInput(1);
                isPressedLeft = false;
            }
            if(event->button.button == SDL_BUTTON_RIGHT)
            {
                RemoveMouseInput(2);
                isPressedRight = false;
            }
            break;
        case SDL_MOUSEMOTION:
            int x,y;
            Uint32 mouseState = SDL_GetMouseState(&x, &y);
            mousePosition.x = x;
            mousePosition.y = y;
            break;
    }
}
GLOBAL::GAME::Direction InputLayer::InputDirection() {
    return inputDirection;
}
GLOBAL::MATH::Vector2D* InputLayer::GetMousePosition(){
    return &mousePosition;

};
void InputLayer::AddInput(int m_mouseInput) {
    auto input = m_mouseInput;
    mouseInputs.push_back(input);
}
void InputLayer::AddInput(GLOBAL::GAME::Direction m_Direction) {
    auto vector = new GLOBAL::MATH::Vector2D(m_Direction);
    if(keyInputs.size() < 2)
    {
        keyInputs.push_back(vector);
        if(GLOBAL::DEBUG)
        {
            GLOBAL::MATH::Vector2D vec;
            vec = *vector;
            std::cout << vec << std::endl;
        }
    }
}

void InputLayer::RemoveMouseInput(int m_mouseInput)
{
    auto input = m_mouseInput;
    mouseInputs.erase(std::remove_if(mouseInputs.begin(), mouseInputs.end(), [&](int v) {return matchesTarget(v,input);}), mouseInputs.end());

}
void InputLayer::RemoveKeyInput(GLOBAL::GAME::Direction m_direction)
{
    auto vector = new GLOBAL::MATH::Vector2D(m_direction);
    keyInputs.erase(std::remove_if(keyInputs.begin(), keyInputs.end(), [&](GLOBAL::MATH::Vector2D* v) {return matchesTarget(*v, *vector);}), keyInputs.end());
}
bool InputLayer::matchesTarget(int _i, int _j)
{
    return _i == _j;
}
bool InputLayer::matchesTarget(GLOBAL::MATH::Vector2D v, GLOBAL::MATH::Vector2D t)
{
    return v.x == t.x && v.y == t.y;
}

bool InputLayer::LeftIsPressed() {
    return isPressedLeft;
}

bool InputLayer::RightIsPressed(){
    return isPressedRight;
}