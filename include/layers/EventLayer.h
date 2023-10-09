#pragma once
#include "Layer.h"

class EventLayer : public ILayer{
public:
    EventLayer(){

    }
    ~EventLayer() = default;
    static EventLayer& Instance(){
        static EventLayer eventLayer;
        return eventLayer;
    }
    void Init() override {

    }

    void Update() override {
        ILayer::Update();
    }

    void Draw() override {
        ILayer::Draw();
    }

    void Reset() override {
        ILayer::Reset();
    }

    void Poll(){
        SDL_PollEvent(&event);
    }

    SDL_Event& GetEvent(){return event;}

    static SDL_Event event;
private:

};