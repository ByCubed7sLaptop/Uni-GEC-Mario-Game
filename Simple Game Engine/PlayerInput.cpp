#include "PlayerInput.h"

#include "Engine/Input.h"
#include "Engine/GameObject.h"
#include <iostream>

PlayerInput::PlayerInput(Core::GameObject* gameObject) 
	: Core::Component(gameObject) 
{
	controller = nullptr;
}


void PlayerInput::Update(float deltaTime)
{
	if (controller == nullptr) return;

	float x = 0;
	float y = 0;

	if (Core::Input::instance->KeyDown(SDLK_w)) y -= 1;
	if (Core::Input::instance->KeyDown(SDLK_a)) {
		x -= 1;
		gameObject->scale.SetX(x);
	}
	if (Core::Input::instance->KeyDown(SDLK_s)) y += 1;
	if (Core::Input::instance->KeyDown(SDLK_d)) {
		x += 1;
		gameObject->scale.SetX(x);
	}

	//std::cout << x << ":" << y << std::endl;

	controller->inputDirection = {x, y};
}

PlayerInput* PlayerInput::SetController(EntityController* newController)
{
	controller = newController;
	return this;
}

EntityController* PlayerInput::GetController()
{
	return controller;
}
