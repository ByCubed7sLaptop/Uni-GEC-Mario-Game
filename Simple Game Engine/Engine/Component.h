#pragma once

#include "Object.h"
#include "Vector.h"

#include <set>

namespace Core {

    // Forward declaration
    class GameObject;

    class Component : public Object
    {
    public:
        Component(GameObject* owner);
        GameObject* Owner();

        virtual void Draw() = 0;
        virtual void Update() = 0;

    protected:
        GameObject* gameObject;
    };
}
