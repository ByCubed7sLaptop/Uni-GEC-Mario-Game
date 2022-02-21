#pragma once

#include "Object.h"
#include "Vector.h"

#include <set>

namespace Core {

    // Forward declaration
    class Components;

    // Represents anything which can exist in a SceneA Scene contains the environments and menus of your game. 
    class GameObject : public Object
    {

        // CONSTRUCTORS
        // ----------------------------------------

        // Default constructor
        GameObject();


        // METHODS
        // ----------------------------------------

        // Get the parent
        GameObject* Parent();

        // Set the parent
        GameObject* SetParent();

        // Returns the children
        std::set<GameObject*> Children();

        // Returns a child via index
        GameObject* Child(int index);

        // Add a child
        void AddChild(GameObject* newChild);

        // Remove a child :)
        void RemoveChild(GameObject* child);

        // Returns the components
        std::set<Components*> GetComponents();

        // Returns a component via index
        GameObject* Component(int index);

        // Add a component
        void AddComponent(Components* newComponent);
        
        // Remove a component
        void RemoveComponent(Components* component);

        // Returns the WORLD position
        Vector<float, 3> Position();
        
        // Sets the WORLD position
        void SetPosition();

        // Returns the LOCAL position
        Vector<float, 3> LocalPosition();

        // Sets the LOCAL position
        void SetLocalPosition();

        // Returns the WORLD rotation
        Vector<float, 3> Rotation();

        // Returns the LOCAL rotation
        void SetRotation();

    private:
        // The parent of the gameobject
        GameObject* parent;

        // The collection of children the gameObject has
        std::set<GameObject*> children;

        // The collection of compoents the gameObject has
        std::set<Components*> components;

        // The WORLD / SCENE position of the gameObject
        Vector<float, 3> position;

        // The LOCAL / RELATIVE position from the gameObjects PARENT
        // If the gameObject has no parent, this is the world position
        Vector<float, 3> localPosition;

        // The WORLD rotation
        float rotation;
    };
}
