#pragma once
#include "Global.h"
#include "SDL_mixer.h"

class SoundMixer {
public:
    SoundMixer() = default;
    ~SoundMixer(){
        for(auto & sound : sounds){
            Mix_FreeChunk(sound);
            sound = nullptr;
        }
        for(auto & m : music){
            Mix_FreeMusic(m);
            m = nullptr;
        }
        Mix_Quit();
    }
    int LoadSound(const char* filename){
        Mix_Chunk *m = nullptr;
        m = Mix_LoadWAV(filename);
        if(m == nullptr){
            printf("Failed to load sound. SDL_Mixer error: %s\n", Mix_GetError());
            return -1;
        }
        sounds.push_back(m);
        return music.size()-1;
    }

    int LoadMusic(const char* filename){
        Mix_Music *m = nullptr;
        m = Mix_LoadMUS(filename);
        if(m == nullptr){
            printf("Failed to load music. SDL_Mixer error: %s\n", Mix_GetError());
            return -1;
        }
        music.push_back(m);
        return music.size()-1;
    }

    int PlaySound(int m_sound){
        Mix_Volume(-1, chunkVolume);
        Mix_PlayChannel(-1, sounds[m_sound], 0);
        return 0;
    }

    int PlayUISound(Mix_Chunk* sound){
        Mix_Volume(-1, chunkVolume);
        Mix_PlayChannel(-1, sound, 0);
        return 0;
    }

    int PlayMusic(int m_music){
        if(Mix_PlayingMusic() == 0){
            Mix_VolumeMusic(musicVolume);
            Mix_PlayMusic(music[m_music], -1);
        }
        return 0;
    }

    void StopMusic(){
        Mix_HaltMusic();
    }

    void PauseMusic(){
        if (Mix_PlayingMusic() == 1)
        {
            if (Mix_PausedMusic() == 1)
            {
                Mix_ResumeMusic();
            }
            else
            {
                Mix_PauseMusic();
            }
        }
    }

    void SetChunkVolume(int m_volume){
        chunkVolume = (MIX_MAX_VOLUME * m_volume) / 100;
    }

    void SetMusicVolume(int m_volume){
        musicVolume = (MIX_MAX_VOLUME * m_volume) / 100;
    }

private:
    std::vector<Mix_Chunk*> sounds;
    std::vector<Mix_Music*> music;
    int chunkVolume, musicVolume;
    //AudioData
    //path
    //channel
    //desired audio level
    //loop

};