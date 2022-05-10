#pragma once

#include "Component.h"
#include "Sprite.h"
#include "Animation.h"

namespace Core
{
    template<typename States, typename Actions>
    class AnimatedSprite : public Component
    {
    public:
        Sprite* sprite;
        Animation<States, Actions> animation;

        AnimatedSprite(Core::GameObject* owner, States startState) : Component(owner), animation(startState)
        {
            sprite = nullptr;

        }

        //void Draw(SDL_Renderer* renderer) override;
        void Update(float deltaTime) override 
        {
            Vector2Int offset = animation.Get();
            SDL_Rect& area = sprite->Source();
            area.x = offset.X();
            area.y = offset.Y();
            area.w = animation.size.X();
            area.h = animation.size.Y();

            //std::cout << "Size: " << animation.size << std::endl;
            animation.Tick();
        }

        AnimatedSprite* LinkSprite(Sprite* newSprite) {
            sprite = newSprite;
            return this;
        }

        AnimatedSprite* SetSize(Vector2Int newSize) {
            animation.size = newSize;
            return this;
        }
    };
}


