#pragma once

// SDL
#include <SDL.h>
#include <stdio.h>

#include "Vector.h"
#include "Input.h"

namespace SDLW 
{
	class SDLWindow
	{
	public:
		SDLWindow(std::string name);
		~SDLWindow();

		bool Update();

		Core::Vector<int, 2> Size();
		void SetSize(Core::Vector<int, 2> newSize);

		SDL_Renderer* Renderer();

	protected:
		std::string title;
		Core::Vector<int, 2> size;

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;

		Core::Input* input;
	};
}