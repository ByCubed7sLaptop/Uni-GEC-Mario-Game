#include "MenuController.h";

#include "Engine/Scene.h"
#include "Engine/Collider.h"
#include "Engine/GameObject.h"
#include "Engine/Input.h"
#include "Engine/Application.h"

MenuController::MenuController(Core::GameObject* owner)
	: Component(owner)
{
	buttons = std::vector<Core::GameObject*>();
	index = 0;
}

void MenuController::Update(float deltaTime)
{
	if (Core::Input::OnKeyDown(SDLK_w)) {
		Add(1);
	}

	if (Core::Input::OnKeyDown(SDLK_SPACE)) {
		// Tell the app to load another scene
		Core::Application::instance->Load(sceneToLoad);
	}
}

void MenuController::ListButton(Core::GameObject* gameObject)
{
	buttons.push_back(gameObject);
}

void MenuController::Add(int value)
{
	index += value;
	index %= buttons.size();
	gameObject->position.Y() = buttons[index]->position.Y();
}

Core::GameObject* MenuController::Get()
{
	return buttons[index];
}

void MenuController::LinkScene(Core::Scene* scene)
{
	sceneToLoad = scene;
}
