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

        void Draw();
        void Update();

    protected:
        GameObject* gameObject;
    };
}
