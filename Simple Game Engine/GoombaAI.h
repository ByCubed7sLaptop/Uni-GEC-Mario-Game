#pragma once

#include "Engine/GameObject.h"
#include "Engine/Component.h"
#include "EntityController.h"
#include "GoombaAnimations.h"

class GoombaAI : public Core::Component
{
public:
	GoombaAI(Core::GameObject* owner) : Component(owner) { isDead = false; }

	virtual void Update(float deltaTime) override;

	GoombaAI* LinkController(EntityController* newController);
	GoombaAI* LinkAnimations(Goomba::Animations* newAnimations);
	GoombaAI* SetTarget(Core::GameObject* newTarget);

private:

	bool isDead;

	EntityController* controller;
	Core::GameObject* target;
	Goomba::Animations* animations;
};

