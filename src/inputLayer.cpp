#include "InputLayer.h"

InputLayer::InputLayer(){
    event = nullptr;
    inputDirection = Global::Game::Direction::NONE;
}
void InputLayer::Init(SDL_Event* m_event) {
    event = m_event;
}
void InputLayer::Update() {
    if(event->type== SDL_KEYDOWN){
        switch (event->key.keysym.sym) {
            case SDLK_w:
                SetInputDirection(Global::Game::Direction::UP);
                break;
            case SDLK_a:
                SetInputDirection(Global::Game::Direction::LEFT);
                break;
            case SDLK_s:
                SetInputDirection(Global::Game::Direction::DOWN);
                break;
            case SDLK_d:
                SetInputDirection(Global::Game::Direction::LEFT);
                break;
        }
    }
    if(event->type == SDL_KEYUP){
        switch (event->key.keysym.sym) {
            case SDLK_w:
                SetInputDirection(Global::Game::Direction::NONE);
                break;
            case SDLK_a:
                SetInputDirection(Global::Game::Direction::NONE);
                break;
            case SDLK_s:
                SetInputDirection(Global::Game::Direction::NONE);
                break;
            case SDLK_d:
                SetInputDirection(Global::Game::Direction::NONE);
                break;
        }
    }
}
Global::Game::Direction InputLayer::InputDirection() {
    return inputDirection;
}
void InputLayer::SetInputDirection(Global::Game::Direction m_Direction) {
    inputDirection = m_Direction;
}