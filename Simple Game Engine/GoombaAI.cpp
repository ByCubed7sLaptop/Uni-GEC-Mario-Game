#include "GoombaAI.h"
#include "Audio.h"

void GoombaAI::Update(float deltaTime)
{
    if (controller == nullptr) return;
    
    float x = 0;
    if (!isDead) {


        if (gameObject->position.X() > target->position.X()) x = -1;
        if (gameObject->position.X() < target->position.X()) x = 1;



        if (std::abs(gameObject->position.X() - target->position.X()) < 8 &&
            gameObject->position.Y() - target->position.Y() < 32)
        {
            animations->animation.Transition(Goomba::Kill);
            // TODO: Add velocity to Mario Y to inact bounce

            Audio::Play("goomba");
            
            isDead = true;
        }

    }

    controller->inputDirection = { x, 0 };
}

GoombaAI* GoombaAI::LinkController(EntityController* newController)
{
    controller = newController;
    return this;
}

GoombaAI* GoombaAI::LinkAnimations(Goomba::Animations* newAnimations)
{
    animations = newAnimations;
    return this;
}

GoombaAI* GoombaAI::SetTarget(Core::GameObject* newTarget)
{
    target = newTarget;
    return this;
}
