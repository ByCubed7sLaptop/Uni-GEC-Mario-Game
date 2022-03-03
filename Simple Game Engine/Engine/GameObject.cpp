#include "GameObject.h"

#include "Object.h"
#include "Scene.h"
#include "Component.h"

namespace Core {

    GameObject::GameObject(Scene* initScene)
        : Object("GameObject")
    {
        scene = initScene;
        parent = nullptr;
        rotation = 0;

        initScene->gameObjects.insert(this);
    }

    Scene* GameObject::GetScene()
    {
        return scene;
    }

    GameObject* GameObject::Parent()
    {
        return parent;
    }

    GameObject* GameObject::SetParent()
    {
        //parent = 
        return this;
    }

    std::set<GameObject*>  GameObject::Children()
    {
        return std::set<GameObject*>();
    }

    GameObject* GameObject::Child(int index)
    {
        // Get via index via std::next
        return *std::next(children.begin(), index);
    }

    void GameObject::AddChild(GameObject* newChild)
    {
        children.insert(newChild);
    }

    void GameObject::RemoveChild(GameObject* child)
    {
        children.erase(child);
    }

    std::set<Component*> GameObject::GetComponents()
    {
        return components;
    }

    Component* GameObject::GetComponent(int index)
    {
        // Get via index via std::next
        return *std::next(components.begin(), index);
    }

    void GameObject::AddComponent(Component* newComponent)
    {
    }

    void GameObject::RemoveComponent(Component* component)
    {
    }

    Vector<float, 3> GameObject::Position() { return position; }
    void GameObject::SetPosition(Vector<float, 3> newPosition) { position = newPosition; }

    Vector<float, 3> GameObject::LocalPosition()
    {
        if (parent == nullptr) return position;

        return { 0 };//parent->Position() - position;
    }

    void GameObject::SetLocalPosition(Vector<float, 3> newLocalPosition)
    {
        //position = parent->Position() + newLocalPosition;
    }

    float GameObject::Rotation() { return rotation; }
    void GameObject::SetRotation(float newRotation) { rotation = newRotation; }

    void GameObject::Destroy()
    {
        // - Remove all references to this gameobject

        // Tell the children we're being destroyed

        // Tell the components we're being destroyed

        // Ask the parent to remove us from being a child
        
        // Ask the scene to remove us from being a gameObject ?
    }
}