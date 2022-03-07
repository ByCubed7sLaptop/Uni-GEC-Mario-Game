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
			std::cerr << "[SDL Error] Unable to load image! " << std::endl << filepath << std::endl << SDL_GetError() << std::endl;
			return false;
		}

		// Set a transparency colour
		Uint32 colorkey = SDL_MapRGB(surface->format, 255, 255, 255);
		SDL_SetColorKey(surface, SDL_TRUE, colorkey);

		// Since SDL_Surface is just the raw pixel data, it is not optimized in any way and should be avoided when rendering.
		// Luckily, you can simply convert an SDL_Surface to SDL_Texture using
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		
		SDL_FreeSurface(surface);
		return true;
	}

	SDL_Texture* SDLTexture::Texture()
	{
		return texture;
	}
}