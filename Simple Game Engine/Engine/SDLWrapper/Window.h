
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

		void Update();
		
		// Gets 
		SDL_Surface* GetSurface();

		int width = 640;
		int height = 480;

	private:
		SDL_Window* window;
		SDL_Surface* surface;
	};
}