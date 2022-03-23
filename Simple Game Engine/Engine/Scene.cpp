#include "Scene.h"

#include "GameObject.h"
#include "Component.h"
#include "Renderer.h"

#include <rapidjson/document.h>

namespace Core {

    Scene::Scene() : Object("Scene")
    {
        gameObjects = std::set<GameObject*>();
        components = std::set<Component*>();
    }

    bool Scene::Update(Uint32 deltaTime)
    {
        for (Component* component : components)
            component->Update(deltaTime);

        return true;
    }

    bool Scene::Render(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        for (Component* component : components)
            component->Draw(renderer);

        return true;
    }

    GameObject* Scene::createGameObject()
    {
        GameObject* newGameObject = new GameObject(this);
        gameObjects.insert(newGameObject);
        return newGameObject;
    }



    // TODO: Serailization, storing and loading objects, ect

    bool Scene::Load(std::string filepath)
    {
        return false;
    }

    bool Scene::Save(std::string filepath)
    {
        return false;
    }
    std::string Scene::ToStorable()
    {

        return "";
    }
    bool Scene::FromStorable(std::string data)
    {
        rapidjson::Document document;
        document.Parse(data.c_str());

        // Extract objects here


        return false;
    }
}