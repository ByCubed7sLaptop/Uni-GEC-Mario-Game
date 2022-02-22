
#include <iostream>

#include "Application.h"
#include "Window.h"
#include "SDLWindow.h"
#include "SDLTexture.h"

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

// SEE: https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php


int main(int argc, char* args[])
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "SDL could not initialize! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 0;
    }



    // Since SDL_Surface is just the raw pixel data, it is not optimized in any way and should be avoided when rendering.
    // Luckily, you can simply convert an SDL_Surface to SDL_Texture using
    // SDL_Texture* SDL_CreateTextureFromSurface

    SDLW::SDLWindow* window = new SDLW::SDLWindow("SDL Tutorial");
    SDL_Renderer* renderer = window->Renderer();
    Core::Application* app = new Core::Application(window);
    
    SDLW::SDLTexture* texture = new SDLW::SDLTexture(renderer);
    texture->Load("Mario/WA.bmp");

    // TODO: Move to app
    //app->Mainloop();

    bool loop = true;
    while (!loop)
    {
        // Update the window
        window->Update();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = true;
                break;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture->Texture(), NULL, NULL);
        SDL_RenderPresent(renderer);
    }


    delete app;
    SDL_DestroyRenderer(renderer);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}