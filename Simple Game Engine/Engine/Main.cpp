
#include <iostream>

#include "Application.h"
#include "Window.h"
#include "SDLWindow.h"

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
    SDL_Surface* gHelloWorld = SDL_LoadBMP("assets/temp.bmp");

    Core::Window* window = new SDLW::SDLWindow("SDL Tutorial");
    Core::Application* app = new Core::Application(window);
    
    
    app->Mainloop();

    delete app;

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}