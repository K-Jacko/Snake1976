//
// Created by Wake on 2/24/2023.
//

#ifndef SLATFORMER_TEXTUREMANAGER_H
#define SLATFORMER_TEXTUREMANAGER_H
#include "SDL.h"
#include "Global.h"
#include "SDL_image.h"
#include "layers/WindowLayer.h"
#include <iostream>
#include <fstream>
#include <filesystem>

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
    TextureManager() {
        if (!IMG_Init(IMG_INIT_PNG)) { std::cout << "ERROR" << SDL_GetError() << std::endl; }
        else { std::cout << "IMG :: Systems Initialised!" << std::endl; }
        //Collect all directory strings from a path and place into a vector
        std::string directoryPath = "assets/Entities/SpriteData";
        std::vector<std::string> filePaths;

        try {
            for (const auto &entry: std::filesystem::directory_iterator(directoryPath)) {
                if (entry.is_regular_file()) {
                    filePaths.push_back(entry.path().string());
                }
            }
        } catch (const std::filesystem::filesystem_error &ex) {
            std::cout << "Error accessing directory: " << ex.what() << std::endl;
        }

        //Process the files using the strings
        for (const auto &filePath: filePaths) {
            std::ifstream inputFile(filePath);
            if (!inputFile) {
                std::cout << "Failed to open the file:" << filePath << std::endl;
            }

            SpriteData spriteData;
            while (inputFile >> spriteData.OriginX >> spriteData.OriginY >> spriteData.TEXTURE_ID >>
                             spriteData.SPRITE_HEIGHT >> spriteData.SPRITE_WIDTH >> spriteData.TEXTURE_X >>
                             spriteData.TEXTURE_Y >> spriteData.TEXTURE_INDEX) {
                spriteDataList.push_back(spriteData);
            }

            inputFile.close();
        }

        //Load all Textures
        for (const auto &texturePath: spriteDataList) {
            SDL_Texture *tex;
            const char *path = texturePath.TEXTURE_ID.c_str();
            tex = IMG_LoadTexture(WindowLayer::Instance().GetRenderer(), path);
            textures.push_back(tex);
        }
        //Get via string}
    }
    int Init();
    ~TextureManager(){
        textures.clear();
        spriteDataList.clear();
        animations.clear();
        textures.shrink_to_fit();
        spriteDataList.shrink_to_fit();
        animations.shrink_to_fit();
    }
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip){SDL_RenderCopyEx(WindowLayer::Instance().GetRenderer(), texture, &src, &dst, 0, nullptr, flip);};
    static void CheckSpriteDataList(){
        for (const auto& spriteData : spriteDataList) {
            std::cout << "OriginX: " << spriteData.OriginX << ", OriginY: " << spriteData.OriginY
                      << ", TEXTURE_ID: " << spriteData.TEXTURE_ID << ", SPRITE_HEIGHT: " << spriteData.SPRITE_HEIGHT
                      << ", SPRITE_WIDTH: " << spriteData.SPRITE_WIDTH << ", TEXTURE_X: " << spriteData.TEXTURE_X
                      << ", TEXTURE_Y: " << spriteData.TEXTURE_Y << ", TEXTURE_INDEX: " << spriteData.TEXTURE_INDEX << std::endl;
        }};
    static SDL_Texture* GetTexture(int index){return textures[index];};
    static SpriteData GetSpriteData(int index){return spriteDataList[index];};
private:
    static std::vector<AnimationData> animations;
    static std::vector<SpriteData> spriteDataList;
    static std::vector<SDL_Texture*> textures;
};
#endif //SLATFORMER_TEXTUREMANAGER_H
