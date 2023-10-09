#pragma once
#include "Global.h"
#include "Layer.h"

class WindowLayer : public ILayer{
public:
    WindowLayer(){
        window = CreateWindow();
        renderer = CreateRenderer();
        if(SDL_Init(SDL_INIT_VIDEO) < 0){std::cout << "ERROR" << SDL_GetError() << std::endl;}
        else{std::cout << "Video Systems :: Initialised!" << std::endl;}
    };
    ~WindowLayer(){
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    };
    static WindowLayer& Instance(){
        static WindowLayer windowLayer;
        return windowLayer;
    };
    SDL_Window* CreateWindow(){
        const char* title = "Snake 1976";
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GLOBAL::SCREEN::SCREEN_WIDTH, GLOBAL::SCREEN::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){std::cerr << "Window :: Error " << SDL_GetError() << std::endl;}
        else {std::cout << "Window :: Initialised! " << SDL_GetError() << std::endl;}
        return window;
    };
    SDL_Renderer* CreateRenderer(){
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer == nullptr){std::cerr << "Renderer :: Error " << SDL_GetError() << std::endl;}
        else {std::cout << "Renderer :: Initialised! " << SDL_GetError() << std::endl;}
        return renderer;
    };
    SDL_Window* GetWindow(){return window;};
    SDL_Renderer* GetRenderer(){return renderer;};
    void Reset()override{};
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

};