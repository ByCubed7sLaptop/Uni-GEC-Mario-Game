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
#include "EntityController.h"
#include "PlayerInput.h"

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Engine/Tilemap.h"

// SEE: https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php


int main(int argc, char* args[])
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "SDL could not initialize! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 0;
    }



    SDLW::SDLWindow* window = new SDLW::SDLWindow("Mario");
    SDL_Renderer* renderer = window->Renderer();
    Core::Application* app = new Core::Application(window);
    
    // CREATE THE SCENE
    Core::Scene* scene = new Core::Scene();
    app->Load(scene);


    // Init the player
    SDLW::SDLTexture* playerTexture = new SDLW::SDLTexture(renderer);
    playerTexture->Load("assets/textures/WA.bmp");

    Core::GameObject* player = new Core::GameObject(scene);
    Sprite* playerSprite = new Sprite(player);

    playerSprite
        ->SetTexture(playerTexture)
        ->SetPivot(Core::Vector<float, 2>({ 0.5, 0.5 }))
        ->SetSize({ 100, 100 });

    EntityController* playerController = new EntityController(player);
    
    PlayerInput* playerInput = new PlayerInput(player);
    playerInput->SetController(playerController);
    //

    // Load Tilemap

    SDLW::SDLTexture* tileTexture = new SDLW::SDLTexture(renderer);
    tileTexture->Load("assets/textures/tilesheet.bmp");

    Core::GameObject* tilemapGO = new Core::GameObject(scene);
    Tilemap* playerTilemap = new Tilemap(tilemapGO);
    playerTilemap
        ->SetTexture(tileTexture)
        ->SetSize({ 100, 100 })
        ->CreateTile({ 0, 0, 16, 16 }, 0);



    app->Mainloop();
    delete app;

    return 0;
}