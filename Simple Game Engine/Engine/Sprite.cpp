#include "Sprite.h"

#include "GameObject.h"

Sprite::Sprite(Core::GameObject* owner) : Component(owner)
{
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    SDL_Rect texture_rect;
    texture_rect.x = gameObject->Position().GetX() - size.GetX() * pivot.GetX();
    texture_rect.y = gameObject->Position().GetY() - size.GetY() * pivot.GetY();
    texture_rect.w = size.GetX();
    texture_rect.h = size.GetY();
    
    SDL_Point center = { size.GetX() * pivot.GetX(), size.GetY() * pivot.GetY() };

    SDL_RendererFlip flip = SDL_RendererFlip(
        (gameObject->scale.GetX() >= 0 ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_HORIZONTAL) |
        (gameObject->scale.GetY() >= 0 ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_VERTICAL)
    );

    gameObject->rotation += 0.005f;
    
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
