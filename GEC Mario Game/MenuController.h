#pragma once

#include "Engine/Component.h"
#include "Engine/Vector.h"

#include <vector>

// Forward declaration
namespace Core { class GameObject; class Collider; }

class MenuController : public Core::Component
{
public:
    MenuController(Core::GameObject* owner);

    virtual void Update(float deltaTime) override;

    // We don't use the draw function
    //virtual void Draw(SDL_Renderer* renderer) override;
    
    void ListButton(Core::GameObject* gameObject);
    void Add(int value);
    Core::GameObject* Get();

    void LinkScene(Core::Scene* scene);

private:
    std::vector<Core::GameObject*> buttons;
    int index;
    Core::Scene* sceneToLoad;
};

