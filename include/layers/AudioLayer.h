#pragma once
#include "Global.h"
#include "SDL_mixer.h"
#include "Layer.h"
#include "SoundMixer.h"


class AudioLayer : public ILayer{
public:
    AudioLayer(){
        soundMixer = new SoundMixer();
        if (SDL_Init(SDL_INIT_AUDIO) < 0) {std::cout << "ERROR" << SDL_GetError() << std::endl;}
        else{std::cout << "Audio :: Systems Initialised!" << std::endl;}
        if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
            std::cout << "ERROR" << Mix_GetError();
        }
        soundMixer->SetChunkVolume(80);
    };

    ~AudioLayer() = default;
    void Init() override {

    }
    static AudioLayer& Instance(){
        static AudioLayer audioLayer;
        return audioLayer;
    }
    void Update() override {
        if(EventLayer::Instance().GetEvent().type == SDL_USEREVENT){
            if(EventLayer::Instance().GetEvent().user.code == 200){
                auto* chunk = static_cast<Mix_Chunk *>(EventLayer::Instance().GetEvent().user.data1);
                soundMixer->PlayUISound(chunk);
            }
        }
    }

    void Draw() override {
        ILayer::Draw();
    }

    void Reset() override {

    }

    SoundMixer* GetSoundMixer(){
        return soundMixer;
    }
private:
    SoundMixer* soundMixer;
};