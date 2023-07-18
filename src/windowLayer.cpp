#include "WindowLayer.h"


WindowLayer::WindowLayer() {
    window = CreateWindow();
    renderer = CreateRenderer();
}
WindowLayer::~WindowLayer(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Window* WindowLayer::CreateWindow() {
    const char* title = "Snake 1976";
    window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, Global::SCREEN::WIDTH, Global::SCREEN::HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr){std::cerr << "Window :: Error " << SDL_GetError() << std::endl;}
    else {std::cout << "Window :: Initialised! " << SDL_GetError() << std::endl;}
    return window;
}
SDL_Renderer* WindowLayer::CreateRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){std::cerr << "Renderer :: Error " << SDL_GetError() << std::endl;}
    else {std::cout << "Renderer :: Initialised! " << SDL_GetError() << std::endl;}
    return renderer;
}
SDL_Window* WindowLayer::GetWindow() {
    return window;
}

SDL_Renderer* WindowLayer::GetRenderer() {
    return renderer;
}