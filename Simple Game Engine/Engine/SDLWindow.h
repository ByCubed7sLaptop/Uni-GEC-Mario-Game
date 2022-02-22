#pragma once

// SDL
#include <SDL.h>
#include <stdio.h>

#include "Window.h"

namespace SDLW 
{
	class SDLWindow : public Core::Window
	{
	public:
		SDLWindow(std::string name);
		~SDLWindow();

		void Update() override;

	private:
		SDL_Window* window;
		SDL_Surface* surface;
	};
}