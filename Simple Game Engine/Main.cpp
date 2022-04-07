#include <iostream>

// TODO: Create an Include header file
#include "Engine/Application.h"
#include "Engine/Window.h"
#include "Engine/SDLWindow.h"
#include "Engine/SDLTexture.h"
#include "Engine/Scene.h"
#include "Engine/GameObject.h"
#include "Engine/Component.h"
#include "Engine/Sprite.h"
#include "Engine/Tilemap.h"
#include "Engine/Collider.h"

#include "EntityController.h"
#include "PlayerInput.h"

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

// SEE: https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php


int main(int argc, char* args[])
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "SDL could not initialize! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 0;
    }



    SDLW::Window* window = new SDLW::Window("Mario");
    SDL_Renderer* renderer = window->Renderer();
    Core::Application* app = new Core::Application(window);
    
    // CREATE THE SCENE
    Core::Scene* scene = new Core::Scene();
    app->Load(scene);


    // Init the player
    SDLW::SDLTexture* playerTexture = new SDLW::SDLTexture(renderer);
    playerTexture->Load("assets/textures/WA.bmp");

    Core::GameObject* player = new Core::GameObject(scene);
    player->SetPosition({ 336, 128 });
    //player->SetPosition({ 0, 0 });

    Sprite* playerSprite = new Sprite(player);
    playerSprite
        ->SetTexture(playerTexture)
        ->SetPivot(Core::Vector<float, 2>({ 0.5, 0.5 }))
        ->SetSize({ 32, 32 });

    Core::Collider* playerCollider = new Core::Collider(player);
    playerCollider->kinematic = true;
    playerCollider->aabb = 31;
    playerCollider->offset = playerSprite->size.Cast<float>() * playerSprite->pivot * -1;

    EntityController* playerController = new EntityController(player);
    playerController->SetSpeed(0.5f);
    playerController->LinkCollider(playerCollider);
    
    PlayerInput* playerInput = new PlayerInput(player);
    playerInput->SetController(playerController);
    //

    // Load Tilemap

    SDLW::SDLTexture* tileTexture = new SDLW::SDLTexture(renderer);
    tileTexture->Load("assets/textures/tilesheet.bmp");

    Core::GameObject* tilemapGO = new Core::GameObject(scene);

    Tilemap* tilemapTilemap = new Tilemap(tilemapGO);
    tilemapTilemap
        ->SetTexture(tileTexture)
        ->SetSize({ 32, 32 })
        ->CreateTile({ 0, 0, 16, 16 }, 0)
        ->CreateTile({ 16, 0, 16, 16 }, 1)
        ->CreateTile({ 32, 0, 16, 16 }, 2);

    for (int i = 0; i < 20; ++i) {
        tilemapTilemap->SetTile({ i,13 }, 0);
        tilemapTilemap->SetTile({ i,14 }, 2);
    }

    Core::Collider* tilemapCollider = new Core::Collider(tilemapGO);
    tilemapCollider->aabb = { 320 * 2, 64 };
    tilemapCollider->offset = { 0, 32 * 13 };


    Core::Collider* tilemapCollider2 = new Core::Collider(tilemapGO);
    tilemapCollider2->aabb = { 320, 64 };
    tilemapCollider2->offset = { 64, 32 * 8 };

    Core::Collider* tilemapCollider3 = new Core::Collider(tilemapGO);
    tilemapCollider3->aabb = { 64, 32*2 };
    tilemapCollider3->offset = { 64, 32 * 10 };

    //

    app->Mainloop();
    delete app;

    return 0;
}