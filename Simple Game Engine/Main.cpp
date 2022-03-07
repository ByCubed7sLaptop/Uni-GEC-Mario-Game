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
    Core::Scene* scene = new Core::Scene();
    
    // CREATE THE SCENE


    // Init the player
    SDLW::SDLTexture* texture = new SDLW::SDLTexture(renderer);
    texture->Load("assets/textures/WA.bmp");

    Core::GameObject* player = new Core::GameObject(scene);
    Sprite* playerSprite = new Sprite(player);

    playerSprite
        ->SetTexture(texture)
        ->SetPivot(Core::Vector<float, 2>({ 0.5, 0.5 }))
        ->SetSize({ 100, 100 });

    EntityController* playerController = new EntityController(player);
    
    PlayerInput* playerInput = new PlayerInput(player);
    playerInput->SetController(playerController);
    //


    // --- - - - - - - - - - ---

    // TODO: Move to application class
    //app->Mainloop();

    Uint32 frameDelay = 0.016;

    bool loop = true;
    while (loop)
    {
        Uint32 frameStart = SDL_GetTicks();

        SDL_RenderClear(renderer);


        // Update the Components
        for (Core::Component* component : scene->components)
            component->Update();
        // https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php

        // Update the window
        loop = window->Update();

        // Render the Components
        for (Core::Component* component : scene->components)
            component->Draw(renderer);

        // Swap the buffer
        SDL_RenderPresent(renderer);


        Uint32 frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
    }


    delete app;
    SDL_DestroyRenderer(renderer);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}