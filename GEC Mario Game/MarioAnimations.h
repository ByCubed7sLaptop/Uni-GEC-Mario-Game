#pragma once

#include "Engine/AnimatedSprite.h"
#include "Engine/Vector.h"
#include "Engine/Animation.h"
#include "EntityGrounded.h"
#include "PlayerInput.h"

// Forward declaration
namespace Core { class GameObject; class Collider; }

namespace Mario {

    enum States {
        Idleing, Running, Turning, Jumping, Dead
    };

    enum Actions {
        Stop, Run, Turn, Jump, Fall, Kill
    };

    class Animations
        : public Core::AnimatedSprite<States, Actions>
    {
    public:
        EntityGrounded* entityGrounded;
        PlayerInput* playerInput;

        //bool moveState;
        bool groundState;

        Animations(Core::GameObject* owner)
            : AnimatedSprite<States, Actions>(owner, States::Idleing)
        {
            animation.AddTransition(States::Idleing, Actions::Run, States::Running);
            animation.AddTransition(States::Running, Actions::Stop, States::Idleing);

            animation.AddTransition(States::Running, Actions::Turn, States::Turning);

            animation.AddTransition(States::Turning, Actions::Run, States::Running);
            animation.AddTransition(States::Turning, Actions::Stop, States::Idleing);

            animation.AddTransition(States::Idleing, Actions::Jump, States::Jumping);
            animation.AddTransition(States::Running, Actions::Jump, States::Jumping);

            animation.AddTransition(States::Jumping, Actions::Fall, States::Running);
            animation.AddTransition(States::Running, Actions::Fall, States::Running);

            animation.AddTransition(States::Idleing, Actions::Kill, States::Dead);
            animation.AddTransition(States::Running, Actions::Kill, States::Dead);
            animation.AddTransition(States::Jumping, Actions::Kill, States::Dead);

            animation.Add(States::Idleing, { 0, 0 });

            animation.Add(States::Running, { 1, 0 });
            animation.Add(States::Running, { 2, 0 });
            animation.Add(States::Running, { 3, 0 });

            animation.Add(States::Turning, { 4, 0 });

            animation.Add(States::Jumping, { 5, 0 });

            animation.Add(States::Dead, { 6, 0 });

            animation.speed *= 2;
        }

        void Update(float deltaTime) override
        {


            bool currentMoveState = playerInput->GetController()->inputDirection.X() == 0;
            //if (moveState != currentMoveState)
            //{
            if (currentMoveState) animation.Transition(Actions::Stop);
            else animation.Transition(Actions::Run);
            //}
            //moveState = currentMoveState;

            bool currentTurnState = playerInput->GetController()->inputDirection.X() < 0 ^ 0 >= entityGrounded->collider->velocity.X();
            if (currentTurnState) animation.Transition(Actions::Turn);
            //else animation.Transition(Actions::Run);

            bool currentGroundState = entityGrounded->isOnGround;
            if (groundState != currentGroundState)
            {
                if (currentGroundState) animation.Transition(Actions::Fall);
                else animation.Transition(Actions::Jump);

                //std::cout << animation.index << std::endl;
            }
            groundState = currentGroundState;

            // super.Update
            inherited::Update(deltaTime);
        }

        Animations* LinkEntityGrounded(EntityGrounded* newEntityGrounded) {
            entityGrounded = newEntityGrounded;
            return this;
        }

        Animations* LinkPlayerInput(PlayerInput* newPlayerInput) {
            playerInput = newPlayerInput;
            return this;
        }


    private:  // Prevents erroneous use by other classes.
        typedef Core::AnimatedSprite<States, Actions> inherited;
    };


}