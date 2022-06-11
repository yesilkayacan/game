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
			-1.0f, -1.0f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		uint32_t indices[3] = { 0, 1, 2 };

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		
		m_VertexBuffer = Engine::VertexBuffer::Create(vertices, sizeof(vertices));
		m_IndexBuffer = Engine::IndexBuffer::Create(indices, sizeof(indices));

		Engine::BufferLayout layout = Engine::BufferLayout(
			{ 
				{ "a_Position", Engine::ShaderDataType::Float, 3 },
				{ "a_Color", Engine::ShaderDataType::Float, 4 } 
			}
		);
		layout.DefineLayout();
		

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

		glGenVertexArrays(1, &m_SquareVertexArray);
		glBindVertexArray(m_SquareVertexArray);
		
		m_SquareVertexBuffer = Engine::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		m_SquareIndexBuffer = Engine::IndexBuffer::Create(squareIndices, sizeof(squareIndices));

		Engine::BufferLayout Squarelayout = Engine::BufferLayout(
			{
				{ "a_Pos", Engine::ShaderDataType::Float, 3 },
				{ "a_Col", Engine::ShaderDataType::Float, 4 }
			}
		);
		Squarelayout.DefineLayout();


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

		glBindVertexArray(m_SquareVertexArray);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//glBindVertexArray(m_VertexArray);
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		
	}
}
