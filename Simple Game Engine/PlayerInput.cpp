#include "PlayerInput.h"

#include "Engine/Input.h"
#include "Engine/GameObject.h"
#include <iostream>
#include "Audio.h"

PlayerInput::PlayerInput(Core::GameObject* gameObject) 
	: Core::Component(gameObject) 
{
	controller = nullptr;

	force = 250;
	cooldown = 0.1f;
	gravity = 0.1f;
	gravityFall = 1.1f;
	coyoteTime = 0.2f;

	lastJump = 0;
	lastJumpPress = 0;

	grounded = nullptr;
}


void PlayerInput::Update(float deltaTime)
{
	if (controller == nullptr) return;

	float x = 0;
	float y = 0;

	// Jumping
	if (Core::Input::KeyDown(SDLK_w)) {
		lastJumpPress = 0;

		if (grounded->isOnGround) {
			y = -force;
			Audio::Play("jump");
			lastJump = 0;
		}
	}


	if (Core::Input::KeyDown(SDLK_a)) {
		x -= 1;
		gameObject->scale.SetX(x);
	}
	if (Core::Input::KeyDown(SDLK_s)) y += 1;
	if (Core::Input::KeyDown(SDLK_d)) {
		x += 1;
		gameObject->scale.SetX(x);
	}

	//std::cout << x << ":" << y << std::endl;

	controller->inputDirection = {x, y};
}

PlayerInput* PlayerInput::LinkController(EntityController* newController)
{
	controller = newController;
	return this;
}

PlayerInput* PlayerInput::LinkGroundChecker(EntityGrounded* newGrounded)
{
	grounded = newGrounded;
	return this;
}

EntityController* PlayerInput::GetController()
{
	return controller;
}
