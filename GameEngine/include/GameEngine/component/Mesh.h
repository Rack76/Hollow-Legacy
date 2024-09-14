#ifndef MESH_H
#define MESH_H

#include <string>
#include "GameEngine/Util/AssetManager.h"
#include "GameEngine/Util/Util.h"
#include "GameEngine/ECS/EntityManager.h"
#include "GameEngine/ECS/Component.h"
#include "GameEngine/component/Transform.h"
#include "glm/gtc/matrix_access.hpp"

namespace HollowEngine
{
	class Mesh : public Component
	{
	public:
		void onCreation()
		{
			if (!EntityManager::hasComponent<Transform>(entityId))
				EntityManager::addComponents(entityId, Transform{});
		}

		void setMesh(std::string&& name)
		{
			vao = AssetManager::Model::getMesh(name);
			meshSet = true;

			vertexCount = AssetManager::Model::getVertexCount(name);
			vertexCountSet = true;
		}

		uint32_t getMesh()
		{
			assertNoAbort(meshSet, "mesh not set");
			return vao;
		}

		int getVertexCount()
		{
			assertNoAbort(vertexCountSet, "vertex count not set");
			return vertexCount;
		}

		void setShaderProgram(std::string&& name)
		{
			shaderProgram = AssetManager::Shader::getShaderProgram(name);
			shaderProgramSet = true;
		}

		uint32_t getShaderProgram()
		{
			assertNoAbort(shaderProgramSet, "shader program not set");
			return shaderProgram;
		}

		void update()
		{
			Transform* transform = EntityManager::getComponent<Transform>(entityId);
			glm::mat4 model = glm::mat4(transform->orientation);
			model = glm::row(model, 3, glm::vec4(transform->translation, 1.0));
			AssetManager::Shader::setUniform("model", &model[0][0]);
		}

	private:
		uint32_t vao;
		bool meshSet = false;

		uint32_t shaderProgram;
		bool shaderProgramSet = false;

		int vertexCount;
		bool vertexCountSet = false;
	};
}

#endif 