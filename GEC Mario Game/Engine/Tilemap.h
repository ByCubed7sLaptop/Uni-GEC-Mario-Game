#pragma once

#include <SDL.h>
#include <stdio.h>

#include <list>
#include <map>

#include "Component.h"
#include "Vector.h"
#include "SDLTexture.h"
#include "Tile.h"
#include <unordered_map>

namespace { class GameObject; }

class Tilemap : public Core::Component
{
public:
    Tilemap(Core::GameObject* owner);

    SDLW::SDLTexture* texture;

    Core::Vector<int, 2> size;

    std::map<Core::Vector<int, 2>, int> tiles;
    std::map<int, SDL_Rect> tilesheet;

    void Draw(SDL_Renderer* renderer);
    void Update(float deltaTime) override;

    Tilemap* SetTexture(SDLW::SDLTexture* newTexture);
    Tilemap* SetSize(Core::Vector<int, 2> newSize);
    Tilemap* CreateTile(SDL_Rect textureOffset, int id);
    Tilemap* SetTile(Core::Vector<int, 2> position, int id);
};

