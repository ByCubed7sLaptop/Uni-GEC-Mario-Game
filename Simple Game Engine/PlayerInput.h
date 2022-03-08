#pragma once

#include "Engine/Component.h"
#include "EntityController.h"

class PlayerInput : public Core::Component
{
public:
	PlayerInput(Core::GameObject* gameObject);

	virtual void Update(float deltaTime) override;

	PlayerInput* SetController(EntityController* newController);
	EntityController* GetController();

private:
	EntityController* controller;
};

