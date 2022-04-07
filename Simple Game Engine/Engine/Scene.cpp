#include "Scene.h"

#include "GameObject.h"
#include "Component.h"
#include "Renderer.h"
#include "Collider.h"

#include <rapidjson/document.h>
#include <iostream>

namespace Core {

    Scene::Scene() : Object("Scene")
    {
        gameObjects = std::set<GameObject*>();
        components = std::set<Component*>();

        // TODO: Move collections to seperate class
        colliders = std::set<Collider*>();
        inCollision = std::map<Collider*, Collider*>();
    }

    bool Scene::Update(Uint32 deltaTime)
    {
        for (Component* component : components)
            component->Update(deltaTime);

        return true;
    }

    bool Scene::Render(SDL_Renderer* renderer)
    {

        for (Component* component : components)
            component->Draw(renderer);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        return true;
    }

    void Scene::CalculateCollisions()
    {
        // -- -- -- -- -- -- -- -- -- -- 
        // - Check for collisions

        // First, collect those who could be colliding
        auto checkCollision = std::map<Collider*, Collider*>();

        // Iterate over the colliders, so that each one is check with the other ONCE
        // O(n) = ( n(n+1) ) / 2 - 1

        //for (Collider* colliderA : colliders) {
        //for (auto itColliderA = colliders.begin(); itColliderA != colliders.end(); ++itColliderA)
        for (auto itColliderA = colliders.begin(); itColliderA != --colliders.end(); ++itColliderA)
        {
            Vector<float, 4> boundsA = (*itColliderA)->Bounds();

            // COPY the current iteration, as the last loop has already done every possible comparrison
            std::set<Collider*>::iterator itColliderB = itColliderA;
            // NOTE: Mind the increment here
            for (++itColliderB; itColliderB != colliders.end(); ++itColliderB)
            {
                // Shouldnt need to check this
                //if (itColliderA == itColliderB) continue;

                Vector<float, 4> boundsB = (*itColliderB)->Bounds();

                // Check X Projection
                if (boundsA.Z() < boundsB.X()) continue;
                if (boundsA.X() > boundsB.Z()) continue;

                // Check Y Projection
                if (boundsA.W() < boundsB.Y()) continue;
                if (boundsA.Y() > boundsB.W()) continue;

                // Add to list
                checkCollision[*itColliderA] = *itColliderB;
            }

            // If IteratorA has reached the second to end then there are no more collisions to check
            if (itColliderA == --colliders.end())
                break;
        }

        // Iterate through the couldBeColliding set
        for (auto collidingIterator = checkCollision.begin(); collidingIterator != checkCollision.end(); ++collidingIterator)
        {
            // Check more indepth
            // Add velocities, ect

            // Check events
            Collider* colliderA = (*collidingIterator).first;
            Collider* colliderB = (*collidingIterator).second;

            // If the collision hasnt happened yet
            //if (inCollision.find(colliderA) != inCollision.end());
            if (inCollision[colliderA] != colliderB) {

                // Raise an OnCollisionEnter event
                std::cout << "- OnCollisionEnter" << std::endl;

                // Add to inCollision
                inCollision[colliderA] = colliderB;
            }
            else {
                // Raise an OnCollsionStay event
                //std::cout << "OnCollsionStay" << std::endl;
            }
        }

        // Check for collisions that are no longer happening
        for (auto collidingIterator = inCollision.cbegin(); collidingIterator != inCollision.cend(); /*No increment*/)
        {
            Collider* colliderA = (*collidingIterator).first;
            Collider* colliderB = (*collidingIterator).second;
            if (checkCollision.find(colliderA) == checkCollision.end()) {
                // These colliders are no longer colliding
                inCollision.erase(collidingIterator++);
                // https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it

                // Raise the OnCollisionExit event
                std::cout << "- OnCollisionExit" << std::endl;
            }
            else {
                ++collidingIterator;
            }
        }
    }

    std::set<Collider*> Scene::BoxTrace(Vector<float, 4> box, Collider* exclude)
    {
        auto checkCollision = std::set<Collider*>();

        for (auto collider : colliders)
        {
            // Exclude
            if (exclude == collider) continue;

            Vector<float, 4> bounds = collider->Bounds();

            // Check Projections
            if (box.Z() < bounds.X()) continue;
            if (box.X() > bounds.Z()) continue;
            if (box.W() < bounds.Y()) continue;
            if (box.Y() > bounds.W()) continue;

            // Add to list
            checkCollision.insert(collider);
        }

        return checkCollision;
    }

    Vector<float, 2> Scene::LineIntersection(Vector<float, 4> lineA, Vector<float, 4> lineB)
    {
        // Get A,B of lines
        float A1 = lineA.W() - lineA.Y();
        float B1 = lineA.X() - lineA.Z();
        float A2 = lineB.W() - lineB.Y();
        float B2 = lineB.X() - lineB.Z();

        // Get denominator
        float denom = A1 * B2 - A2 * B1;
        
        // ASSUME that the lines are NOT parallel
        //if (denom == 0) return false;
        
        // Get C of first and second lines
        float C2 = A2 * lineB.X() + B2 * lineB.Y();
        float C1 = A1 * lineA.X() + B1 * lineA.Y();

        // Invert denom
        float invDenom = 1 / denom;
        return Vector<float, 2>({ (B2 * C1 - B1 * C2) * invDenom, (A1 * C2 - A2 * C1) * invDenom });
    }






    GameObject* Scene::CreateGameObject()
    {
        GameObject* newGameObject = new GameObject(this);
        gameObjects.insert(newGameObject);
        return newGameObject;
    }



    // TODO: Serailization, storing and loading objects, ect

    bool Scene::Load(std::string filepath)
    {
        return false;
    }
    bool Scene::Save(std::string filepath)
    {
        return false;
    }

    std::string Scene::ToStorable()
    {
        return "";
    }
    bool Scene::FromStorable(std::string data)
    {
        rapidjson::Document document;
        document.Parse(data.c_str());

        // Extract objects here


        return false;
    }
}