
// STD
#include <string>

// SDL
#include <SDL.h>
#include <stdio.h>

#pragma once

namespace SDLW {
	class Window {
	public:
		Window(std::string name);
		~Window();

		SDL_Surface* GetWindowSurface();
		void Update();
		

		SDL_Window* window;
		SDL_Surface* surface;

		int width = 640;
		int height = 480;
	};
}