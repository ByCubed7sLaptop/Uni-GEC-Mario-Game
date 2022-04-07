#pragma once

// SDL
#include <SDL.h>
#include <stdio.h>

#include "Vector.h"
#include "Input.h"

namespace SDLW
{
	class Window
	{
	public:
		Window(std::string name);
		~Window();

		bool Update();

		// Gets
		Core::Vector<int, 2> Size();
		SDL_Renderer* Renderer();

		// Sets
		void SetSize(Core::Vector<int, 2> newSize);

	protected:
		std::string title;
		Core::Vector<int, 2> size;

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;

		Core::Input* input;
	};
}