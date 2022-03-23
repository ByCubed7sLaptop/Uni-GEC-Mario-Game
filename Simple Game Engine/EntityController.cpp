#include "EntityController.h"

#include "Engine/GameObject.h"
#include <iostream>

EntityController::EntityController(Core::GameObject* owner)
	: Component(owner)
{
	speed = 1;
	weight = 1;
	resistance = 0.99f;

	inputDirection = {0};
	acceleration = {0};
}

void EntityController::Update(float deltaTime)
{
	acceleration += inputDirection * speed * 0.01f;
	acceleration *= resistance;

	gameObject->SetPosition(gameObject->Position() + acceleration.Resize<3>() * deltaTime);
}
