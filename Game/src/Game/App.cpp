#include "epch.h"
#include "App.h"

#include "glad/glad.h"

const std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec4 vertexColor;			

			void main()
			{
				vertexColor = a_Color;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

const std::string fragmentSrc = R"(
			#version 330 core
			
			in vec4 vertexColor;

			out vec4 FragColor;

			void main()
			{
				FragColor = vertexColor;
			}
		)";

namespace App
{
	App::App()
	{
		// Draw triangle
		//m_VertexArray = Engine::OpenGLVertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		uint32_t indices[3] = { 0, 1, 2 };

		m_VertexArray = Engine::VertexArray::Create();
		std::shared_ptr<Engine::VertexBuffer> m_VertexBuffer = Engine::VertexBuffer::Create(vertices, sizeof(vertices));
		std::shared_ptr<Engine::IndexBuffer> m_IndexBuffer = Engine::IndexBuffer::Create(indices, sizeof(indices));
		std::shared_ptr<Engine::BufferLayout> layout = std::make_shared<Engine::BufferLayout>(Engine::BufferLayout(
			{ 
				{ "a_Position", Engine::ShaderDataType::Float, 3 },
				{ "a_Color", Engine::ShaderDataType::Float, 4 } 
			}
		));
		m_VertexArray->AddVertexBuffer(m_VertexBuffer, layout);
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		

		float squareVertices[7 * 4] = {
			 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f
		};

		uint32_t squareIndices[6] = {
			0, 1, 2,
			2, 3, 0 
		};

		m_SquareVertexArray = Engine::VertexArray::Create();
		m_VertexBuffer = Engine::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		m_IndexBuffer = Engine::IndexBuffer::Create(squareIndices, sizeof(squareIndices));
		layout = std::make_shared<Engine::BufferLayout>(Engine::BufferLayout(
			{
				{ "a_Position", Engine::ShaderDataType::Float, 3 },
				{ "a_Color", Engine::ShaderDataType::Float, 4 }
			}
		));
		m_SquareVertexArray->AddVertexBuffer(m_VertexBuffer, layout);
		m_SquareVertexArray->SetIndexBuffer(m_IndexBuffer);

		m_Shader = Engine::Shader::Create(vertexSrc, fragmentSrc);
	}

	bool App::HandleEvent(Engine::Event& e)
	{
		APP_INFO("Event: {0}", e.ToString());
		return false;
	}

	void App::OnApplicationUpdate()
	{
		Engine::Renderer::BeginScene();

		m_Shader->Bind();

		m_SquareVertexArray->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//glBindVertexArray(m_VertexArray);
		m_VertexArray->Bind();
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		
	}
}
