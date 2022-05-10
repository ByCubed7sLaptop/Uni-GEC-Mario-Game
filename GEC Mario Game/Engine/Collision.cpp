#include "Collision.h"

#include "Collider.h"

namespace Core {

	Collision::Collision(Collider* _colliderA, Collider* _colliderB) {
		colliderA = _colliderA;
		colliderB = _colliderB;
		point = {0};

		colliderAVelocity = colliderA->velocity;
		colliderBVelocity = colliderB->velocity;
	};

}