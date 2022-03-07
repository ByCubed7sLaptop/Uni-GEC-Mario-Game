#pragma once

#include "Object.h"
#include "Vector.h"

#include <SDL.h>
#include <stdio.h>

#include <set>

namespace Core {

    // Forward declaration
    class GameObject;

    class Component : public Object
    {
    public:
        Component(GameObject* owner);

        GameObject* Owner();

        // Abstract update method, called every frame.
        virtual void Update() = 0;

        // Draw method, called every frame, not abstract due to not all object needing to be drawn 
        virtual void Draw(SDL_Renderer* renderer);// = 0;

    protected:
        GameObject* gameObject;
    };
}
