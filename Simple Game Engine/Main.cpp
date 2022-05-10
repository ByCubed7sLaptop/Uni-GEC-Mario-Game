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
#include "EntityGrounded.h"
#include "MenuController.h"
#include "MarioAnimations.h"
#include "GoombaAnimations.h"
#include "Audio.h"

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "GoombaAI.h"

// SEE: https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php

Core::Scene* titleScene;
Core::Scene* gameScene;
SDLW::SDLTexture* mainSpritesheet;

Core::GameObject* CreatePlayer(Core::Scene* scene) {

    Core::GameObject* player = new Core::GameObject(scene);
    player->SetPosition({ 300, 128 });
    //player->SetPosition({ 0, 0 });

    Sprite* playerSprite = new Sprite(player);
    playerSprite
        ->SetTexture(mainSpritesheet)
        ->SetSource({ 0, 0, 16, 16 })
        ->SetPivot({ 0.5, 0.5 })
        ->SetSize({ 32, 32 });

    Core::Collider* playerCollider = new Core::Collider(player);
    playerCollider->kinematic = true;
    playerCollider->aabb = 31;
    playerCollider->offset = playerSprite->Size().Cast<float>() * playerSprite->Pivot() * -1;

    EntityController* playerController = new EntityController(player);
    playerController->SetSpeed(0.5f);
    playerController->LinkCollider(playerCollider);

    EntityGrounded* playerJump = new EntityGrounded(player);
    playerJump->LinkCollider(playerCollider);

    PlayerInput* playerInput = new PlayerInput(player);
    playerInput->LinkController(playerController);
    playerInput->LinkGroundChecker(playerJump);
    playerInput->force = 250.0f * 1.5f;

    Mario::Animations* playerAnimations = new Mario::Animations(player);
    playerAnimations
        ->LinkEntityGrounded(playerJump)
        ->LinkPlayerInput(playerInput)
        ->LinkSprite(playerSprite)
        ->SetSize(16);
    
    return player;
}

Core::GameObject* CreateGoomba(Core::Scene* scene, Core::GameObject* player) {

    Core::GameObject* goomba = new Core::GameObject(scene);
    //player->SetPosition({ 300, 128 });
    //player->SetPosition({ 0, 0 });

    Sprite* goombaSprite = new Sprite(goomba);
    goombaSprite
        ->SetTexture(mainSpritesheet)
        ->SetSource({ 0, 0, 16, 16 })
        ->SetPivot({ 0.5, 0.5 })
        ->SetSize({ 32, 32 });

    Core::Collider* goombaCollider = new Core::Collider(goomba);
    goombaCollider->kinematic = true;
    goombaCollider->aabb = 31;
    goombaCollider->offset = goombaSprite->Size().Cast<float>() * goombaSprite->Pivot() * -1;

    EntityController* goombaController = new EntityController(goomba);
    goombaController->SetSpeed(0.2f);
    goombaController->LinkCollider(goombaCollider);

    GoombaAI* goombaAI = new GoombaAI(goomba);
    goombaAI
        ->LinkController(goombaController)
        ->SetTarget(player);

    Goomba::Animations* goombaAnimations = new Goomba::Animations(goomba);
    goombaAnimations
        ->LinkEntityController(goombaController)
        ->LinkSprite(goombaSprite)
        ->SetSize(16);

    goombaAI
        ->LinkAnimations(goombaAnimations);

    return goomba;
}






Core::Scene* LoadSceneTitle(Core::Application* app)
{
    SDLW::Window* window = app->Window();
    Core::Scene* scene = new Core::Scene();

    // - - Init title card

    SDLW::SDLTexture* titleTexture = new SDLW::SDLTexture(window->Renderer());
    titleTexture->Load("assets/textures/Title.bmp");

    Core::GameObject* title = new Core::GameObject(scene);
    title->SetPosition({ window->Size().X() / 2.0f, 128 });

    Sprite* titleSprite = new Sprite(title);
    titleSprite
        ->SetTexture(titleTexture)
        ->SetPivot(Core::Vector2Float({ 0.5, 0.5 }));
    titleSprite // BUG: Size gets lost if method-chained to the above
        ->SetSize(titleSprite->Size() * 2);


    // - - Init Play button(s)

    SDLW::SDLTexture* play1Texture = new SDLW::SDLTexture(window->Renderer());
    play1Texture->Load("assets/textures/PlayerGame1.bmp");

    Core::GameObject* play1 = new Core::GameObject(scene);
    play1->SetPosition({ window->Size().X() / 2.0f, 300 });

    Sprite* play1Sprite = new Sprite(play1);
    play1Sprite
        ->SetTexture(play1Texture)
        ->SetPivot(Core::Vector2Float({ 0.5f, 0.5f }));
    play1Sprite
        ->SetSize(play1Sprite->Size() * 2);


    SDLW::SDLTexture* play2Texture = new SDLW::SDLTexture(window->Renderer());
    play2Texture->Load("assets/textures/PlayerGame2.bmp");

    Core::GameObject* play2 = new Core::GameObject(scene);
    play2->SetPosition({ window->Size().X() / 2.0f, 325 });

    Sprite* play2Sprite = new Sprite(play2);
    play2Sprite
        ->SetTexture(play2Texture)
        ->SetPivot(Core::Vector2Float({ 0.5f, 0.5f }));
    play2Sprite
        ->SetSize(play2Sprite->Size() * 2);

    // Mushroom selection

    SDLW::SDLTexture* mushroomTexture = new SDLW::SDLTexture(window->Renderer());
    mushroomTexture->Load("assets/textures/Mushroom.bmp");

    Core::GameObject* mushroom = new Core::GameObject(scene);
    mushroom->SetPosition({ (window->Size().X() / 2.0f) - 100, 300 });

    Sprite* mushroomSprite = new Sprite(mushroom);
    mushroomSprite
        ->SetTexture(mushroomTexture)
        ->SetPivot(Core::Vector2Float({ 0.5f, 0.5f }));
    mushroomSprite
        ->SetSize(mushroomSprite->Size() * 2);

    MenuController* mushroomController = new MenuController(mushroom);
    mushroomController->ListButton(play1);
    mushroomController->ListButton(play2);
    mushroomController->LinkScene(gameScene);



    // - - Init Title background

    SDLW::SDLTexture* titleBgTexture = new SDLW::SDLTexture(window->Renderer());
    titleBgTexture->Load("assets/textures/titleBackground.bmp");

    Core::GameObject* titleBg = new Core::GameObject(scene);
    titleBg->SetPosition({ 0, window->Size().Y() * 1.0f });

    Sprite* titleBgSprite = new Sprite(titleBg);
    titleBgSprite
        ->SetTexture(titleBgTexture)
        ->SetPivot(Core::Vector2Float({ 0, 1 }));
    titleBgSprite
        ->SetSize({ window->Width(), titleBgSprite->Height() * (window->Width() / titleBgSprite->Width()) });



    return scene;
}



Core::Scene* LoadSceneGame(Core::Application* app)
{
    SDLW::Window* window = app->Window();
    Core::Scene* scene = new Core::Scene();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    auto player = CreatePlayer(scene);

    //*/

    CreateGoomba(scene, player);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    //* Init Tilemap
    SDLW::SDLTexture* tileTexture = new SDLW::SDLTexture(window->Renderer());
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
        tilemapTilemap->SetTile({ i,12 }, 0);
        tilemapTilemap->SetTile({ i,13 }, 1);
        tilemapTilemap->SetTile({ i,14 }, 1);
    }

    Core::Collider* tilemapCollider = new Core::Collider(tilemapGO);
    tilemapCollider->aabb = { 320 * 2, 64 };
    tilemapCollider->offset = { 0, 32 * 12 };


    Core::Collider* tilemapCollider2 = new Core::Collider(tilemapGO);
    tilemapCollider2->aabb = { 320, 64 };
    tilemapCollider2->offset = { 64, 32 * 6 };

    Core::Collider* tilemapCollider3 = new Core::Collider(tilemapGO);
    tilemapCollider3->aabb = { 64, 32 * 2 };
    tilemapCollider3->offset = { 64, 32 * 9 };

    Core::Collider* tilemapCollider4 = new Core::Collider(tilemapGO);
    tilemapCollider4->aabb = { 32 * 4, 32 * 1 };
    tilemapCollider4->offset = { 32 * 14, 32 * 9 };

    return scene;
}





int main(int argc, char* args[])
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "SDL could not initialize! SDL_Error:" << std::endl << SDL_GetError() << std::endl;
        return 0;
    }
    SDL_Init(SDL_INIT_AUDIO);

    Audio::Init("music_stage_clear");
    Audio::Load("jump-small", "jump");
    Audio::Load("", "jump");

    Core::Application* app = new Core::Application("Mario");

    mainSpritesheet = new SDLW::SDLTexture(app->Window()->Renderer());
    mainSpritesheet->Load("assets/textures/Super Mario Spritesheet.bmp");
    
    gameScene = LoadSceneGame(app);
    titleScene = LoadSceneTitle(app);

    app->Load(titleScene);
    app->Window()->SetBackgroundColour({ 33, 153, 243 });

    app->Mainloop();
    delete app;

    //Quit SDL subsystems
    SDL_CloseAudio();
    SDL_Quit();

    return 0;
}