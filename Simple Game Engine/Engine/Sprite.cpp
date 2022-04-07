#include "Sprite.h"

#include "GameObject.h"

Sprite::Sprite(Core::GameObject* owner) : Component(owner)
{
    rotation = 0;
    texture = nullptr;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    SDL_Rect texture_rect;
    texture_rect.x = gameObject->Position().X() - size.X() * pivot.X();
    texture_rect.y = gameObject->Position().Y() - size.Y() * pivot.Y();
    texture_rect.w = size.X();
    texture_rect.h = size.Y();
    
    SDL_Point center = { size.X() * pivot.X(), size.Y() * pivot.Y() };

    SDL_RendererFlip flip = SDL_RendererFlip(
        (gameObject->scale.X() >= 0 ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_HORIZONTAL) |
        (gameObject->scale.Y() >= 0 ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_VERTICAL)
    );
    
    //SDL_RenderCopy(renderer, texture->Texture(), NULL, &texture_rect);
    SDL_RenderCopyEx(renderer, texture->Texture(), NULL, &texture_rect, gameObject->rotation, &center, flip);
}

void Sprite::Update(float deltaTime)
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
