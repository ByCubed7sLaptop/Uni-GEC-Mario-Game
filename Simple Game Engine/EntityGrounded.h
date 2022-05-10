#pragma once

#include "Engine/Component.h"
#include "Engine/Vector.h"

// Forward declaration
namespace Core { class GameObject; class Collider; }
class EntityController;

class EntityGrounded: public Core::Component
{
public:
    EntityGrounded(Core::GameObject* owner);

    virtual void Update(float deltaTime) override;

    Core::Collider* collider;
    EntityGrounded* LinkCollider(Core::Collider* newCollider);
    
    bool isOnGround;
    float groundBoarderSize;
};

