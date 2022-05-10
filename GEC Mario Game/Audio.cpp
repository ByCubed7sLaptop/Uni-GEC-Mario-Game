#include "Audio.h"

SDL_AudioDeviceID OpenAudioDeviceId = 0;
static std::map<std::string, Audio::Wav> Cache;
 
void Audio::Init(std::string file)
{
    file = "assets/audio/" + file + ".wav";

    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;

    SDL_LoadWAV(file.c_str(), &wavSpec, &wavBuffer, &wavLength);

    OpenAudioDeviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    SDL_FreeWAV(wavBuffer);
}

void Audio::Load(std::string file, std::string name)
{
    file = "assets/audio/" + file + ".wav";
    Wav wav = Wav();
    SDL_LoadWAV(file.c_str(), &wav.spec, &wav.buffer, &wav.length);
    Cache[name] = wav;
}

void Audio::Play(std::string name)
{
    Wav wav = Cache[name];
    int success = SDL_QueueAudio(OpenAudioDeviceId, wav.buffer, wav.length);
    SDL_PauseAudioDevice(OpenAudioDeviceId, 0);
    //SDL_FreeWAV(wav.buffer);
}
