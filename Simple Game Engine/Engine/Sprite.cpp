#include "Sprite.h"

#include "GameObject.h"

Sprite::Sprite(Core::GameObject* owner) : Component(owner)
{
    rotation = 0;
    texture = nullptr;
    
    source.x, source.y, source.w, source.h = 0;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
    SDL_Rect destination;
    destination.x = gameObject->Position().X() - size.X() * pivot.X();
    destination.y = gameObject->Position().Y() - size.Y() * pivot.Y();
    destination.w = size.X();
    destination.h = size.Y();

    //std::cout << source.x << " " << source.y << " " << source.w << " " << source.h << std::endl;
    
    SDL_Point center = { size.X() * pivot.X(), size.Y() * pivot.Y() };

    SDL_RendererFlip flip = SDL_RendererFlip(
        (gameObject->scale.X() >= 0 ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_HORIZONTAL) |
        (gameObject->scale.Y() >= 0 ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_VERTICAL)
    );
    
    //SDL_RenderCopy(renderer, texture->Texture(), NULL, &texture_rect);
    SDL_RenderCopyEx(renderer, texture->Texture(), &source, &destination, gameObject->rotation, &center, flip);
}

void Sprite::Update(float deltaTime)
{
}

Sprite* Sprite::SetTexture(SDLW::SDLTexture* newTexture)
{
    if (texture == nullptr) {
        source.w = newTexture->Width();
        source.h = newTexture->Height();
        size = { newTexture->Width(), newTexture->Height() };
    }
    texture = newTexture;
    return this;
}

Sprite* Sprite::SetSource(SDL_Rect newSource)
{
    source = newSource;
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

SDLW::SDLTexture*& Sprite::Texture()
{
    return texture;
}

SDL_Rect& Sprite::Source()
{
    return source;
}

Core::Vector<int, 2>& Sprite::Size()
{
    return size;
}

int& Sprite::Width() { return size.X(); }
int& Sprite::Height() { return size.Y(); }

Core::Vector<float, 2>& Sprite::Pivot()
{
    return pivot;
}
