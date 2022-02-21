#include "GameObject.h"

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
    return nullptr;
}

void Core::GameObject::AddChild(GameObject* newChild)
{
}

void Core::GameObject::RemoveChild(GameObject* child)
{
}

std::set<Components*> Core::GameObject::GetComponents()
{
    return std::set<Components*>();
}

GameObject* Core::GameObject::Component(int index)
{
    return nullptr;
}

void Core::GameObject::AddComponent(Components* newComponent)
{
}

void Core::GameObject::RemoveComponent(Components* component)
{
}

Vector<float, 3> Core::GameObject::Position()
{
    return Vector<float, 3>();
}

void Core::GameObject::SetPosition()
{
}

Vector<float, 3> Core::GameObject::LocalPosition()
{
    return Vector<float, 3>();
}

void Core::GameObject::SetLocalPosition()
{
}

Vector<float, 3> Core::GameObject::Rotation()
{
    return Vector<float, 3>();
}

void Core::GameObject::SetRotation()
{
}
