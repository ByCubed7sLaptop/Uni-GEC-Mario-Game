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
        Vector<float, 2> Position();
        
        // Sets the WORLD position
        void SetPosition(Vector<float, 2> newPosition);

        // Returns the LOCAL position
        Vector<float, 2> LocalPosition();

        // Sets the LOCAL position
        void SetLocalPosition(Vector<float, 2> newLocalPosition);

        // Returns the WORLD rotation
        float Rotation();

        // Returns the LOCAL rotation
        void SetRotation(float newRotation);

        // Tell the gameObject to destroy itself.
        // Simular to the deconstructor
        void Destroy();

        // The WORLD / SCENE position of the gameObject
        Vector<float, 2> position;

        // The WORLD rotation
        float rotation;

        // The WORLD / SCENE position of the gameObject
        Vector<float, 2> scale;

    private:

        Scene* scene;

        // The parent of the gameobject
        GameObject* parent;

        // The collection of children the gameObject has
        std::set<GameObject*> children;

        // The collection of compoents the gameObject has
        std::set<Component*> components;
    };
}
