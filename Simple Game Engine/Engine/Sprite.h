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

	SDLW::SDLTexture* texture;

	Core::Vector<int, 2> size;
	Core::Vector<float, 2> pivot;
	float rotation;

	void Draw(SDL_Renderer* renderer) override;
	void Update(float deltaTime) override;

	Sprite* SetTexture(SDLW::SDLTexture* newTexture);
	Sprite* SetSize(Core::Vector<int, 2> newSize);
	Sprite* SetPivot(Core::Vector<float, 2> newPivot);
};

