#pragma once

#include "Engine/Component.h"
#include "Engine/Vector.h"

// Forward declaration
namespace Core { class GameObject; }

class EntityController : public Core::Component
{
public:
    EntityController(Core::GameObject* owner);

    virtual void Update(float deltaTime) override;

    // We don't use the draw function
    //virtual void Draw(SDL_Renderer* renderer) override;

    // The direction the entity `wants` to go in
    Core::Vector<float, 2> inputDirection;
    Core::Vector<float, 2> acceleration;

    // The acceleration rate
    float speed;

    // How weighted the entity is
    float weight;

    // The deacceleration rate to 0
    float resistance;
};

