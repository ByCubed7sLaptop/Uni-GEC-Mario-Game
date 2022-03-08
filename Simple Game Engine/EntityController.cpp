#include "EntityController.h"

#include "Engine/GameObject.h"
#include <iostream>

EntityController::EntityController(Core::GameObject* owner)
	: Component(owner)
{
	speed = 1;
	weight = 1;
	resistance = 0.9;

	inputDirection = {0};
	acceleration = {0};
}

void EntityController::Update(float deltaTime)
{
	acceleration += inputDirection * speed;
	//acceleration *= resistance;

	gameObject->SetPosition(gameObject->Position() + acceleration.Resize<3>() * deltaTime);
}
