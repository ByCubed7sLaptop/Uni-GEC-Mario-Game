#include "Collider.h"

#include "GameObject.h"
#include "Scene.h"

#include <iostream>

namespace Core 
{
	Collider::Collider(GameObject* owner) 
		: Component(owner)
	{
		owner->GetScene()->colliders.insert(this);
		
		state = ACTIVE;
		kinematic = false;

		velocity = { 0 };
		torque = 0;

		airDensity = 0.99f;
	}

	void Collider::Update(float deltaTime)
	{
		// Is the object static?
		if (!kinematic) return;

		Vector<float, 4> bounds = Bounds();

		// - Get next frame offset
		Vector<float, 4> nextPositionOffset = Vector<float, 4>::Append<2, 2>(velocity, velocity) * deltaTime;
		
		Vector<float, 4> nextPositionOffsetX = Vector<float, 4>(nextPositionOffset);
		nextPositionOffsetX.Y() = 0;
		nextPositionOffsetX.W() = 0;

		Vector<float, 4> nextPositionOffsetY = Vector<float, 4>(nextPositionOffset);
		nextPositionOffsetY.X() = 0;
		nextPositionOffsetY.Z() = 0;

		// - Trace next position
		//auto trace = scene->BoxTrace(bounds + nextPositionOffset, this);
		auto traceX = scene->BoxTrace(bounds + nextPositionOffsetX, this);
		auto traceY = scene->BoxTrace(bounds + nextPositionOffsetY, this);


		// If we're not going to hit something along the Y axis
		if (traceY.size() == 0) {
			// Move on momentum
			gameObject->position.Y() += velocity.Y() * deltaTime;

		}
		else {
			// Bounce
			velocity.SetY(0);
		}

		if (traceX.size() == 0) {
			gameObject->position.X() += velocity.X() * deltaTime;
		}
		else {
			velocity.SetX(0);
		}

		// Apply air resistance
		velocity *= airDensity;

		// Add gravity
		velocity += {0, 0.008f};


		//std::cout << "position: " << gameObject->position << std::endl;
	}

	void Collider::Draw(SDL_Renderer* renderer)
	{
		auto bounds = Bounds();

		// TODO: Should probably rearrange the bounds to fit this more nicely
		SDL_Rect rect;
		rect.x = bounds.X();
		rect.y = bounds.W();
		rect.w = bounds.Z() - bounds.X();
		rect.h = bounds.Y() - bounds.W();

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderDrawRect(renderer, &rect);
		//SDL_RenderFillRect(renderer, &rect);

	}

	Collider* Collider::SetShape(std::vector<Vector<float, 2>> newPoints)
	{
		points = newPoints;
		return this;
	}

	bool Collider::ContainsPoint(Vector<float, 2> position)
	{
		// If the line equation is y = ax + b and the coordinates of a point is (n,j) then compare j and a x n + b, 
		// for example if j > a x n + b then the point is above the line, etc.
		// Then, test with every neirhbouring pair of points

		// TODO: Use a circular linked list to iterate over

		for (int index = 0; index < points.size(); ++index) 
		{
			// y = ax + b
			Vector<float, 2> pointA = points[index];
			// BUG: Will raise an out of index error
			// Use a circular linked list instead
			Vector<float, 2> pointB = points[index+1];
			Vector<float, 2> difference = pointB - pointA;

			float gradiant = difference.X() / difference.Y();
			float offset = pointA.Y() - gradiant * pointA.X();

			if (position.Y() < gradiant * position.X() + offset)
				return false;
		}

		return true;
	}

	void Collider::OnCollisionEnter(Collider* otherCollider)
	{
		// TODO: Change OtherCollider to collision object


	}

	void Collider::OnCollisionStay(Collider* otherCollider)
	{
	}

	void Collider::OnCollisionExit(Collider* otherCollider)
	{
	}

	bool Collider::IsActive() { return state == ACTIVE; }
	bool Collider::IsAsleep() { return state == ASLEEP; }
	bool Collider::IsKinematic() { return kinematic; }
	
	Vector<float, 4> Collider::Bounds()
	{
		/*Vector<float, 4> newBound = {
			gameObject->position.X(),
			gameObject->position.Y(),
			gameObject->position.X() + aabb.X(),
			gameObject->position.Y() + aabb.Y()
		};*/
		Vector<float, 4> newBound = Vector<float, 4>::Append<2, 2>(gameObject->position + offset, gameObject->position + offset + aabb);

		return newBound;
	}
}