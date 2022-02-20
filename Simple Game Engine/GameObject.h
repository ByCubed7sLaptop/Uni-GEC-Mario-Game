#pragma once

#include "Object.h"
#include "Vector.h"

#include <set>

namespace Core {    

    class GameObject : public Object
    {
        // Default constructor
        GameObject();

        std::set<GameObject> children;
        std::set<Components> components;

        Vector<float, 3> position;
        Vector<float, 3> localPosition;
        float rotation;
    };
}
