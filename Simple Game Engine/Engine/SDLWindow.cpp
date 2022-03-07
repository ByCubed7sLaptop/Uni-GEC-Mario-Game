#include "SDLWindow.h"

#include "Input.h"

#include <iostream>

namespace SDLW
{
    SDLWindow::SDLWindow(std::string name)
    {
        title = name;
        size = { 640, 480 };

        // Init varibles
        window = nullptr;
        surface = nullptr;

        //Create window
        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.GetX(), size.GetY(), SDL_WINDOW_SHOWN);
        if (window == NULL) {
            std::cout << "Window could not be created! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL){
            std::cout << "Renderer could not be created! SDL Error:" << std::endl << SDL_GetError() << std::endl;
            return;
        }

        // Get window surface
        surface = SDL_GetWindowSurface(window);


        // Fill the surface white
        //SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
        //
        // Update the surface
        //SDL_UpdateWindowSurface(window);

        // Wait two seconds
        //SDL_Delay(2000);

        input = new Core::Input();
    }

    SDLWindow::~SDLWindow()
    {
        SDL_DestroyWindow(window);
        window = nullptr;
        surface = nullptr;
    }

    SDL_Renderer* SDLWindow::Renderer()
    {
        return SDL_GetRenderer(window);
    }

    bool SDLWindow::Update() {

        // Poll events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // We are only worried about SDL_KEYDOWN and SDL_KEYUP events
            switch (event.type) {
            case SDL_KEYDOWN:
                std::cout << "Key press detected" << std::endl;
                Core::Input::instance->KeyChangeState(event.key.keysym.sym, 1);
                std::cout << "event.key.keysym.sym = " << event.key.keysym.sym << std::endl;
                break;

            case SDL_KEYUP:
                std::cout << "Key release detected" << std::endl;
                Core::Input::instance->KeyChangeState(event.key.keysym.sym, 0);
                break;

            case SDL_QUIT:
                return false;

            default:
                break;
            }
        }

        return true;
    }


    Core::Vector<int, 2> SDLWindow::Size()
    {
        return size;
    }

    void SDLWindow::SetSize(Core::Vector<int, 2> newSize)
    {
        size = newSize;
    }
}