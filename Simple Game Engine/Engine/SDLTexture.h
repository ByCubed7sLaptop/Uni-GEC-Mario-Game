
// STD
#include <string>

// SDL
#include <SDL.h>
#include <stdio.h>

#pragma once

namespace SDLW {

	class SDLTexture {
	public:
		SDLTexture(SDL_Renderer* renderer);
		~SDLTexture();

		// Load a texture via filepath
		bool Load(std::string filepath);

		SDL_Texture* Texture();

	private:
		// The renderer reference
		SDL_Renderer* renderer;
		SDL_Texture* texture;

	};
}