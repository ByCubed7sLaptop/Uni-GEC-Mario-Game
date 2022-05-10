#include "SDLWindow.h"

#include "Input.h"

#include <iostream>

namespace SDLW
{
    Window::Window(std::string name)
    {
        title = name;
        size = { 640, 480 };

        // Init varibles
        window = nullptr;
        surface = nullptr;

        //Create window
        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.X(), size.Y(), SDL_WINDOW_SHOWN);
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

    }

    Window::~Window()
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
        SDL_DestroyWindow(window);
        window = nullptr;
        surface = nullptr;

    }

    SDL_Renderer* Window::Renderer()
    {
        return SDL_GetRenderer(window);
    }

    bool Window::Update() 
    {
        Core::Input::Tick();

        // Poll events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // We are only worried about SDL_KEYDOWN and SDL_KEYUP events
            switch (event.type) {
            case SDL_KEYDOWN:
                //std::cout << "Key press detected" << std::endl;
                Core::Input::KeyChangeState(event.key.keysym.sym, 1);
                //std::cout << "event.key.keysym.sym = " << event.key.keysym.sym << std::endl;
                break;

            case SDL_KEYUP:
                //std::cout << "Key release detected" << std::endl;
                Core::Input::KeyChangeState(event.key.keysym.sym, 0);
                break;

            case SDL_QUIT:
                return false;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, backgroundColour.X(), backgroundColour.Y(), backgroundColour.Z(), 0);

        return true;
    }


    Core::Vector<int, 2> Window::Size()
    {
        return size;
    }

    int& Window::Width() { return size.X(); }
    int& Window::Height() { return size.Y(); }

    void Window::SetSize(Core::Vector<int, 2> newSize)
    {
        size = newSize;
        SDL_SetWindowSize(window, newSize.X(), newSize.Y());
    }

    void Window::SetBackgroundColour(Core::RGB colour)
    {
        backgroundColour = colour;
    }
}