#include "EntityController.h"

#include "Engine/GameObject.h"
#include "Engine/Collider.h"
#include <iostream>

EntityController::EntityController(Core::GameObject* owner)
	: Component(owner)
{
	speed = 1;
	inputDirection = 0;
}

void EntityController::Update(float deltaTime)
{
	//if (collider == nullptr) return;

	//acceleration += inputDirection * speed * 0.01f;
	//acceleration *= resistance;
	//gameObject->position += acceleration * deltaTime;

	//std::cout << "Input Direction " << inputDirection.X() << ":" << inputDirection.Y() << std::endl;
	collider->velocity += inputDirection * speed * 0.01f;

	// 'Jump'
	//if (inputDirection.Y() == -1) {
		//collider->velocity.SetY(-1); 
	//}
}

void EntityController::LinkCollider(Core::Collider* _collider)
{
	collider = _collider;
}

EntityController* EntityController::SetSpeed(float newSpeed)
{
	speed = newSpeed;
	return this;
}
