#include "GameObject.h"

namespace Core {


    GameObject::GameObject() 
        : Object("GameObject")
    {
        parent = nullptr;
        rotation = 0;
    }

    GameObject* Core::GameObject::Parent()
    {
        return nullptr;
    }

    GameObject* Core::GameObject::SetParent()
    {
        return nullptr;
    }

    std::set<GameObject*> Core::GameObject::Children()
    {
        return std::set<GameObject*>();
    }

    GameObject* Core::GameObject::Child(int index)
    {
        // Get via index via std::next
        return *std::next(children.begin(), index);
    }

    void Core::GameObject::AddChild(GameObject* newChild)
    {
        children.insert(newChild);
    }

    void Core::GameObject::RemoveChild(GameObject* child)
    {
        children.erase(child);
    }

    std::set<Component*> Core::GameObject::GetComponents()
    {
        return components;
    }

    Component* Core::GameObject::GetComponent(int index)
    {
        // Get via index via std::next
        return *std::next(components.begin(), index);
    }

    void Core::GameObject::AddComponent(Component* newComponent)
    {
    }

    void Core::GameObject::RemoveComponent(Component* component)
    {
    }

    Vector<float, 3> Core::GameObject::Position() { return position; }
    void Core::GameObject::SetPosition(Vector<float, 3> newPosition) { position = newPosition; }

    Vector<float, 3> Core::GameObject::LocalPosition()
    {
        if (parent == nullptr) return position;

        return { 0 };//parent->Position() - position;
    }

    void Core::GameObject::SetLocalPosition(Vector<float, 3> newLocalPosition)
    {
        //position = parent->Position() + newLocalPosition;
    }

    float Core::GameObject::Rotation() { return rotation; }
    void Core::GameObject::SetRotation(float newRotation) { rotation = newRotation; }

    void GameObject::Destroy()
    {
        // - Remove all references to this gameobject

        // Tell the children we're being destroyed

        // Tell the components we're being destroyed

        // Ask the parent to remove us from being a child
        
        // Ask the scene to remove us from being a gameObject ?
    }
}