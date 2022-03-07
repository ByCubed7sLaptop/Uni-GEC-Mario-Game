#pragma once

#include "Engine/Component.h"
#include "EntityController.h"

class PlayerInput : public Core::Component
{
public:
	PlayerInput(Core::GameObject* gameObject);

	virtual void Update() override;

	void SetController(EntityController* newController);
	EntityController* GetController();

	EntityController* controller;
};

