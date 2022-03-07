#include "PlayerInput.h"
#include "Engine/Input.h"

PlayerInput::PlayerInput(Core::GameObject* gameObject) 
	: Core::Component(gameObject) 
{
	controller = nullptr;
}


void PlayerInput::Update()
{
	if (controller == nullptr) return;

	float x = 0;
	float y = 0;

	if (Core::Input::instance->KeyDown((int)"w")) y -= 1;
	if (Core::Input::instance->KeyDown((int)"a")) x -= 1;
	if (Core::Input::instance->KeyDown((int)"s")) y += 1;
	if (Core::Input::instance->KeyDown((int)"d")) x += 1;

	controller->inputDirection = {x, y};
}

void PlayerInput::SetController(EntityController* newController)
{
	controller = newController;
}

EntityController* PlayerInput::GetController()
{
	return controller;
}
