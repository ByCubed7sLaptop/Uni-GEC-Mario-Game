#include "EntityController.h"

#include "Engine/GameObject.h"
#include <iostream>

EntityController::EntityController(Core::GameObject* owner)
	: Component(owner)
{
	speed = 2;
	weight = 1;
	resistance = 0.9;
}

void EntityController::Update()
{
	acceleration += inputDirection * speed;
	//acceleration *= resistance;

	gameObject->SetPosition(gameObject->Position() + Core::Vector<float, 3>({ 0.01,0.01,0 }));// acceleration.Resize<3>());
}
