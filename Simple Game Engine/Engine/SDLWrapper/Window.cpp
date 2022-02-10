#include "Window.h"

#include <iostream>

#include <SDL.h>
#include <stdio.h>

namespace SDLW {

	Window::Window(std::string name)
	{
        // Init varibles
        window = nullptr;
        surface = nullptr;

        //Create window
        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            std::cout << "Window could not be created! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
            return;
        }

       
        // Get window surface
        surface = SDL_GetWindowSurface(window);
             
        // Fill the surface white
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        
        // Update the surface
        SDL_UpdateWindowSurface(window);

        // Wait two seconds
        SDL_Delay(2000);
        
	}

    Window::~Window()
    {
        SDL_DestroyWindow(window);
        window = nullptr;
        surface = nullptr;
    }

    SDL_Surface* Window::GetSurface()
    {
        return surface;
    }

    void Window::Update()
    {
        SDL_UpdateWindowSurface(window);
    }

}

