
#include "Engine/SDLWrapper/Window.h"

#include <iostream>

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


// SEE: https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php


int main(int argc, char* args[])
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "SDL could not initialize! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 0;
    }

    SDLW::Window* window = new SDLW::Window("SDL Tutorial");
    SDL_Surface* screenSurface = window->GetSurface();

    // Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    window->Update();

    // Wait two seconds
    //SDL_Delay(2000);
    
    //Destroy window
    delete window;

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}