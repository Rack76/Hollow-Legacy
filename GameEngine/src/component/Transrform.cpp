#include "GameEngine/component/Transform.h"

namespace HollowEngine
{
	Transform& Transform::rotateXWorld(float& angle)
	{
		orientation = glm::rotate(glm::mat4(orientation), glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
		return *this;
	}

	Transform& Transform::rotateYWorld(float& angle)
	{
		orientation = glm::rotate(glm::mat4(orientation), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
		return *this;
	}

	Transform& Transform::identity()
	{
		orientation = glm::mat4(1.0f);
		return *this;
	}
}