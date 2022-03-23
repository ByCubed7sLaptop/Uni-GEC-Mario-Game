#include "Tilemap.h"

#include "GameObject.h"

Tilemap::Tilemap(Core::GameObject* owner) : Component(owner)
{
	tiles = std::map<Core::Vector<int, 2>, int>();
	tilesheet = std::map<int, SDL_Rect >();
}

void Tilemap::Draw(SDL_Renderer* renderer)
{
	std::map<Core::Vector<int, 2>, int>::iterator it;
	for (it = tiles.begin(); it != tiles.end(); it++) 
	{
		SDL_Rect texture_rect = tilesheet[it->second];
		texture_rect.x = gameObject->Position().GetX() ;
		texture_rect.y = gameObject->Position().GetY() ;
		texture_rect.w = size.GetX();
		texture_rect.h = size.GetY();

		SDL_Point center = { 0,0 };//{ size.GetX() * pivot.GetX(), size.GetY() * pivot.GetY() };

		//apply_surface(box.x - camera.x, box.y - camera.y, tileSheet, screen, &clips[type]);
		SDL_RenderCopyEx(renderer, texture->Texture(), &tilesheet[it->second], &texture_rect, gameObject->rotation, &center, SDL_RendererFlip::SDL_FLIP_NONE);
	}
}

void Tilemap::Update(float deltaTime)
{
}

Tilemap* Tilemap::CreateTile(SDL_Rect textureOffset, int id)
{
	tilesheet[id] = textureOffset;
	return this;
}

Tilemap* Tilemap::SetTile(Core::Vector<int, 2> position, int id)
{
	tiles[position] = id;
	return this;
}

Tilemap* Tilemap::SetTexture(SDLW::SDLTexture* newTexture)
{
	texture = newTexture;
	return this;
}

Tilemap* Tilemap::SetSize(Core::Vector<int, 2> newSize)
{
	size = newSize;
	return this;
}
