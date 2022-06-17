#include "epch.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Engine
{
	void Camera::Init()
	{

		m_View = glm::mat4(1.0f);
		m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -0.5f));
	}

	std::shared_ptr<Camera> Camera::Create()
	{
		return std::make_shared<Camera>();
	}

	void Camera::Rotate()
	{
	}

	void Camera::Translate()
	{
	}

	glm::mat4 Camera::GetViewMatrix()
	{
		return m_View;
	}

	//void Camera::InitwRotation(glm::vec3 position, glm::vec3 rotate)
	//{
	//}

}