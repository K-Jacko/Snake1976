//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_TEXTUREMANAGER_H
#define SLATFORMER_TEXTUREMANAGER_H
#include "SDL.h"
#include "Global.h"

struct SpriteData{
    float OriginX = 0;
    float OriginY = 0;
    std::string TEXTURE_ID = "nullptr";
    float SPRITE_HEIGHT = 0;
    float SPRITE_WIDTH = 0;
    float TEXTURE_X = 0;
    float TEXTURE_Y = 0;
    int TEXTURE_INDEX = 0;
};
struct AnimationData{
    static const int WALKING_ANIMATION_FRAMES;
    std::vector<SDL_Rect> SPRITE_CLIPS;
    SDL_Texture* SPRITE_SHEET_TEXTURE;
};

class TextureManager {
public:
    int Init();
    ~TextureManager();
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
    static void CheckSpriteDataList();
    static SDL_Texture* GetTexture(int index);
    static SpriteData GetSpriteData(int index);
private:
    static std::vector<AnimationData> animations;
    static std::vector<SpriteData> spriteDataList;
    static std::vector<SDL_Texture*> textures;
};
#endif //SLATFORMER_TEXTUREMANAGER_H
