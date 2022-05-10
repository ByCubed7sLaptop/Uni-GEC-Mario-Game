#pragma once

#include "Engine/AnimatedSprite.h"
#include "Engine/Vector.h"
#include "Engine/Animation.h"
#include "EntityGrounded.h"
#include "PlayerInput.h"

// Forward declaration
namespace Core { class GameObject; class Collider; }

namespace Goomba {

    enum States {
        Idleing, Running, Dead
    };

    enum Actions {
        Stop, Run, Kill
    };

    class Animations
        : public Core::AnimatedSprite<States, Actions>
    {
    public:
        EntityController* entityController;

        //bool moveState;
        bool groundState;

        Animations(Core::GameObject* owner)
            : AnimatedSprite<States, Actions>(owner, Idleing)
        {
            animation.AddTransition(Idleing, Run, Running);
            animation.AddTransition(Running, Stop, Idleing);

            animation.AddTransition(Idleing, Kill, Dead);
            animation.AddTransition(Running, Kill, Dead);


            animation.Add(Idleing, { 0, 2 });
            animation.Add(Idleing, { 1, 2 });

            animation.Add(Running, { 0, 2 });
            animation.Add(Running, { 1, 2 });

            animation.Add(Dead, { 2, 2 });

            animation.speed /= 4.0f;
        }

        void Update(float deltaTime) override
        {
            bool currentMoveState = entityController->inputDirection.X() == 0;

            //if (moveState != currentMoveState)
            //{
            if (currentMoveState) animation.Transition(Stop);
            else animation.Transition(Run);
            //}
            //moveState = currentMoveState;

            // super.Update
            inherited::Update(deltaTime);
        }

        Animations* LinkEntityController(EntityController* newEntityController) {
            entityController = newEntityController;
            return this;
        }


    private:  // Prevents erroneous use by other classes.
        typedef Core::AnimatedSprite<States, Actions> inherited;
    };


}