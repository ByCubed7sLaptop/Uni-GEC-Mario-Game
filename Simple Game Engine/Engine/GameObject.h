#pragma once

#include "Object.h"
#include "Vector.h"

#include <set>

namespace Core {

    // Forward declaration
    class Component;
    class Scene;

    // Represents anything which can exist in a SceneA Scene contains the environments and menus of your game. 
    class GameObject : public Object
    {
    public:

        // CONSTRUCTORS
        // ----------------------------------------

        // Default constructor
        GameObject(Scene* scene);


        // METHODS
        // ----------------------------------------
        
        // Return the scene
        Scene* GetScene();

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
        std::set<Component*> GetComponents();

        // Returns a component via index
        Component* GetComponent(int index);

        // Add a component
        void AddComponent(Component* newComponent);
        
        // Remove a component
        void RemoveComponent(Component* component);

        // Returns the WORLD position
        Vector<float, 3> Position();
        
        // Sets the WORLD position
        void SetPosition(Vector<float, 3> newPosition);

        // Returns the LOCAL position
        Vector<float, 3> LocalPosition();

        // Sets the LOCAL position
        void SetLocalPosition(Vector<float, 3> newLocalPosition);

        // Returns the WORLD rotation
        float Rotation();

        // Returns the LOCAL rotation
        void SetRotation(float newRotation);

        // Tell the gameObject to destroy itself.
        // Simular to the deconstructor
        void Destroy();

    private:

        Scene* scene;

        // The parent of the gameobject
        GameObject* parent;

        // The collection of children the gameObject has
        std::set<GameObject*> children;

        // The collection of compoents the gameObject has
        std::set<Component*> components;

        // The WORLD / SCENE position of the gameObject
        Vector<float, 3> position;

        // The LOCAL / RELATIVE position from the gameObjects PARENT
        // If the gameObject has no parent, this is the world position
        Vector<float, 3> localPosition;

        // The WORLD rotation
        float rotation;
    };
}
