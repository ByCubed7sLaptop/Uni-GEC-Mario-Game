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

    bool Scene::Render(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        
        return true;
    }

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