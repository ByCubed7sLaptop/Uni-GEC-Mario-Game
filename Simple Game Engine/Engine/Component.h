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

        virtual void Draw(SDL_Renderer* renderer) = 0;
        virtual void Update() = 0;

    protected:
        GameObject* gameObject;
    };
}
