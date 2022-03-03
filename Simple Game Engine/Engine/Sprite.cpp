#include "Sprite.h"

#include "GameObject.h"

Sprite::Sprite(Core::GameObject* owner) : Component(owner)
{
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    SDL_Rect texture_rect;
    texture_rect.x = gameObject->Position().GetX();// -size.GetX() * pivot.GetX();
    texture_rect.y = gameObject->Position().GetY();// -size.GetY() * pivot.GetY();
    texture_rect.w = size.GetX();
    texture_rect.h = size.GetY();
    SDL_RenderCopy(renderer, texture->Texture(), NULL, &texture_rect);
}

void Sprite::Update()
{
}

Sprite* Sprite::SetTexture(SDLW::SDLTexture* newTexture)
{
    texture = newTexture;
    return this;
}

Sprite* Sprite::SetSize(Core::Vector<int, 2> newSize)
{
    size = newSize;
    return this;
}

Sprite* Sprite::SetPivot(Core::Vector<float, 2> newPivot)
{
    pivot = newPivot;
    return this;
}
