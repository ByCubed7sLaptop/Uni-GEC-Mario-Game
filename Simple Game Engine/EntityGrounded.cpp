#include "EntityGrounded.h"

#include "Engine/Scene.h"
#include "Engine/Collider.h"

EntityGrounded::EntityGrounded(Core::GameObject* owner)
	: Component(owner)
{
    isOnGround = false;
    groundBoarderSize = 0.05f;
}

void EntityGrounded::Update(float deltaTime)
{
    if (collider == nullptr) return;

    auto bounds = collider->Bounds();
    bounds += Core::Vector<float, 4>({ groundBoarderSize, 0.1f, -groundBoarderSize, 0.1f });

    bool isTouchingGround = scene->BoxTrace(bounds, collider).size() != 0;

    isOnGround = isTouchingGround && collider->velocity.Y() > 0;
}

EntityGrounded* EntityGrounded::LinkCollider(Core::Collider* newCollider)
{
    collider = newCollider;
	return this;
}
