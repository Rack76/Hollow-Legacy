#include "GameEngine/ecs/EntityManager.h"

namespace HollowEngine
{
	int EntityManager::activeGroup = 0;
	std::unordered_map<int, Group> EntityManager::groups;
}