#pragma once

#include "Engine/Component.h"

#include "EntityGrounded.h"
#include "EntityController.h"

class PlayerInput : public Core::Component
{
public:
	PlayerInput(Core::GameObject* gameObject);

	virtual void Update(float deltaTime) override;

	PlayerInput* LinkController(EntityController* newController);
	PlayerInput* LinkGroundChecker(EntityGrounded* newGrounded);
	EntityController* GetController();

	// - - Jumping
	
	// The force of the jump
	float force;

	// The time since of the last active jump
	float lastJump;

	// The cooldown from the lastJump
	float cooldown;

	// The base gravity from jumping
	float gravity;

	// The fall modifier for the gravity
	float gravityFall;
	
	// The time to jump save
	float coyoteTime;

	// The time since of the last jump press
	float lastJumpPress;

private:
	EntityController* controller;
	EntityGrounded* grounded;
};

