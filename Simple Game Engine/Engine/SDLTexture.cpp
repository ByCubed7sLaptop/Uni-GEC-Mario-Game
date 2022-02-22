#include "SDLTexture.h"

#include <iostream>
#include <string>

namespace SDLW {

	SDLTexture::SDLTexture(SDL_Renderer* renderer)
	{
		this->renderer = renderer;
		texture = nullptr;
	}

	SDLTexture::~SDLTexture()
	{
		if (texture != nullptr) {
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}
	}

	bool SDLTexture::Load(std::string filepath)
	{
		SDL_Surface* surface = SDL_LoadBMP(filepath.c_str());
		if (surface == NULL)
		{
			std::cerr << "Unable to load image! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		return true;
	}

	SDL_Texture* SDLTexture::Texture()
	{
		return texture;
	}
}