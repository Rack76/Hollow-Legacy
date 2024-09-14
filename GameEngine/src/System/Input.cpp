#include "GameEngine/System/Input.h"
#include "GameEngine/Core/Window.h"
#include "GameEngine/enum/InputEnum.h"
#include "GameEngine/ECS/EntityManager.h"
#include "GameEngine/ECS/Archetype.h"
#include "GameEngine/Util/RTTI.h"
#include "GameEngine/component/PlayerInput.h"
#include "GameEngine/enum/EntityProcInput.h"
#include <vector>

void runActions(int trigger, std::any data = 0)
{
	std::vector<HollowEngine::Archetype*> archetypes = HollowEngine::EntityManager::getArchetypesWith({ HollowEngine::RTTI::typeId<HollowEngine::PlayerInput>() });
	for (HollowEngine::Archetype* archetype : archetypes)
	{
		for (auto pair : archetype->entities)
		{
			HollowEngine::PlayerInput* playerInput = (HollowEngine::PlayerInput*)pair.second.at(HollowEngine::RTTI::typeId<HollowEngine::PlayerInput>());
			playerInput->runActions(trigger, data);
		}
	}
}

void keyCallback(int key, int action)
{
	switch (action)
	{
	case PRESS:
		switch (key)
		{
		case ESC_KEY:
			HollowEngine::Window::getInstance()->close();
			break;
		case A_KEY_PRESS:
			runActions(A_KEY_PRESS);
			break;
		case D_KEY_PRESS:
			runActions(D_KEY_PRESS);
			break;
		case SPACE_KEY_PRESS:
			runActions(SPACE_KEY_PRESS);
			break;
		case LEFT_SHIFT_KEY_PRESS:
			runActions(LEFT_SHIFT_KEY_PRESS);
			break;
		case W_KEY_PRESS:
			runActions(W_KEY_PRESS);
			break;
		case S_KEY_PRESS:
			runActions(S_KEY_PRESS);
			break;
		}
		break;

	case RELEASE:
		switch (key)
		{
		case A_KEY_RELEASE:
			runActions(A_KEY_RELEASE);
			break;
		case D_KEY_RELEASE:
			runActions(D_KEY_RELEASE);
			break;
		case SPACE_KEY_RELEASE:
			runActions(SPACE_KEY_RELEASE);
			break;
		case LEFT_SHIFT_KEY_RELEASE:
			runActions(LEFT_SHIFT_KEY_RELEASE);
			break;
		case W_KEY_RELEASE:
			runActions(W_KEY_RELEASE);
			break;
		case S_KEY_RELEASE:
			runActions(S_KEY_RELEASE);
			break;
		}
		break;
	}
}

void cursorCallback(double x, double y, float dt)
{
	runActions(MOUSE_MOTION, std::make_tuple(x, y, dt));
}

namespace HollowEngine
{
	void Input::init()
	{
		Window::getInstance()->setCursorCallback(cursorCallback);
		Window::getInstance()->setKeyCallback(keyCallback);
		Window::getInstance()->setDT(&dt);
	}

	void Input::run(float _dt)
	{
		dt = _dt;
		Window::getInstance()->pollEvents();
	}
}