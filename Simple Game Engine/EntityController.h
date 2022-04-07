#pragma once

#include "Engine/Component.h"
#include "Engine/Vector.h"

// Forward declaration
namespace Core { class GameObject; class Collider; }

class EntityController : public Core::Component
{
public:
    EntityController(Core::GameObject* owner);

    virtual void Update(float deltaTime) override;

    // We don't use the draw function
    //virtual void Draw(SDL_Renderer* renderer) override;
    
    void LinkCollider(Core::Collider* collider);

    EntityController* SetSpeed(float newSpeed);

    // The direction the entity `wants` to go in
    Core::Vector<float, 2> inputDirection;

    // Collider
    Core::Collider* collider;

    // The acceleration rate
    float speed;

    // The deacceleration rate to 0
    //float resistance;
};

