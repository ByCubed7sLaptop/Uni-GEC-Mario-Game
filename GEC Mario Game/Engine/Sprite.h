#pragma once

#include <SDL.h>
#include <stdio.h>

#include "Component.h"
#include "Vector.h"
#include "SDLTexture.h"

namespace { class GameObject; }

class Sprite : public Core::Component
{
public:
	Sprite(Core::GameObject* owner);

	void Draw(SDL_Renderer* renderer) override;
	void Update(float deltaTime) override;

	Sprite* SetTexture(SDLW::SDLTexture* newTexture);
	Sprite* SetSource(SDL_Rect newSource);
	Sprite* SetSize(Core::Vector<int, 2> newSize);
	Sprite* SetPivot(Core::Vector<float, 2> newPivot);

	SDLW::SDLTexture*& Texture();
	SDL_Rect& Source();
	Core::Vector<int, 2>& Size();
	int& Width();
	int& Height();
	Core::Vector<float, 2>& Pivot();

private:
	SDLW::SDLTexture* texture;
	SDL_Rect source;

	Core::Vector<int, 2> size;
	Core::Vector<float, 2> pivot;
	float rotation;
};

