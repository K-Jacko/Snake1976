#pragma once
#include "Layer.h"
#include "Global.h"
#include "EventLayer.h"

class InputLayer : public ILayer{
public:
    InputLayer(){
        event = &EventLayer::Instance().GetEvent();
        isPressedRight = isPressedLeft = false;
    };
    ~InputLayer(){
        keyInputs.clear();
        keyInputs.shrink_to_fit();
        mouseInputs.clear();
        mouseInputs.shrink_to_fit();
    };
    static InputLayer& Instance(){
        static InputLayer instance;
        return instance;
    };
    void Init() override{};
    void Update() override{
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
    };
    void Reset() override{
        keyInputs.clear();
        keyInputs.shrink_to_fit();
        mouseInputs.clear();
        mouseInputs.shrink_to_fit();
    };
    std::vector<GLOBAL::MATH::Vector2D*> GetKeyInputs(){return keyInputs;}
    bool RightIsPressed(){return isPressedRight;};
    bool LeftIsPressed(){return isPressedLeft;};
    std::vector<int> GetMouseInputs(){return mouseInputs;}
    GLOBAL::MATH::Vector2D GetMousePosition(){return mousePosition;};
private:
    void AddInput(int m_mouseInput){
        auto input = m_mouseInput;
        mouseInputs.push_back(input);
    };
    void AddInput(GLOBAL::GAME::Direction m_Direction){
        auto vector = new GLOBAL::MATH::Vector2D(m_Direction);
        if(keyInputs.size() < 2){
            keyInputs.push_back(vector);
        }
    };
    void RemoveMouseInput(int m_mouseInput){
        auto input = m_mouseInput;
        mouseInputs.erase(std::remove_if(mouseInputs.begin(), mouseInputs.end(), [&](int v) {return matchesTarget(v,input);}), mouseInputs.end());
    };
    void RemoveKeyInput(GLOBAL::GAME::Direction m_direction){
        auto vector = new GLOBAL::MATH::Vector2D(m_direction);
        keyInputs.erase(std::remove_if(keyInputs.begin(), keyInputs.end(), [&](GLOBAL::MATH::Vector2D* v) {return matchesTarget(*v, *vector);}), keyInputs.end());
    };
    static bool matchesTarget(int _i, int _j){return _i == _j;};
    static bool matchesTarget(GLOBAL::MATH::Vector2D v, GLOBAL::MATH::Vector2D t){return v.x == t.x && v.y == t.y;};
    bool isPressedLeft, isPressedRight;
    std::vector<GLOBAL::MATH::Vector2D*> keyInputs;
    std::vector<int> mouseInputs;
    GLOBAL::MATH::Vector2D mousePosition;
    SDL_Event* event;
};