#pragma once

#include <string>
#include <iostream>
//#include <stdlib.h>
#include <map>

#include <SDL.h>
#include <stdio.h>
#include "SDL_audio.h"

// This is so very much just botched together ;-;
// Todo: 
// - Use a competent Audio implementation
// - Fix Audio queue lag with channels

namespace Audio 
{
    struct Wav {
        SDL_AudioSpec spec;
        Uint32 length;
        Uint8* buffer;
    };

    static SDL_AudioDeviceID OpenAudioDeviceId;
    static std::map<std::string, Wav> Cache;
    void Init(std::string file);
    void Load(std::string file, std::string name);
    void Play(std::string name);
}