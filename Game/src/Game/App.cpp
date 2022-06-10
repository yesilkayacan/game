#include "epch.h"
#include "App.h"

#include "glad/glad.h"

const std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

const std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
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

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		
		m_VertexBuffer = Engine::VertexBuffer::Create(vertices, sizeof(vertices));
		m_IndexBuffer = Engine::IndexBuffer::Create(indices, sizeof(indices));

		Engine::BufferLayout layout = Engine::BufferLayout(
			{ 
				{ "a_pos", Engine::ShaderDataType::Float, 3 },
				{ "a_calor", Engine::ShaderDataType::Float, 4 } 
			}
		);
		layout.DefineLayout();
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
		//glEnableVertexAttribArray(0);
		//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
		//glEnableVertexAttribArray(1);
		



		//std::shared_ptr<Engine::OpenGLVertexBuffer> vertexBuffer = Engine::OpenGLVertexBuffer::Create(vertices, sizeof(vertices));
		//Engine::BufferLayout layout = {
		//	{ Engine::ShaderDataType::Float3, "a_Position" },
		//	{ Engine::ShaderDataType::Float4, "a_Color" }
		//};
		//vertexBuffer->SetLayout(layout);
		//m_VertexArray->AddVertexBuffer(vertexBuffer);

		//
		//std::shared_ptr<Engine::OpenGLIndexBuffer> indexBuffer = Engine::OpenGLIndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		//m_VertexArray->SetIndexBuffer(indexBuffer);

		//// Draw Square
		//m_SquareVA = OpenGLVertexArray::Create();

		//float squareVertices[5 * 4] = {
		//	-0.5f, -0.5f, 0.0f,
		//	 0.5f, -0.5f, 0.0f,
		//	 0.5f,  0.5f, 0.0f,
		//	-0.5f,  0.5f, 0.0f
		//};

		//std::shared_ptr<OpenGLVertexBuffer> squareVB = OpenGLVertexBuffer::Create(squareVertices, sizeof(squareVertices));
		//squareVB->SetLayout({
		//	{ ShaderDataType::Float3, "a_Position" }
		//	});
		//m_SquareVA->AddVertexBuffer(squareVB);

		//uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		//std::shared_ptr<OpenGLIndexBuffer> squareIB = OpenGLIndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		//m_SquareVA->SetIndexBuffer(squareIB);

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

		//Engine::Renderer::Submit(m_SquareVA);
		m_Shader->Bind();
		glBindVertexArray(m_VertexArray);
		//Engine::Renderer::Submit(m_VertexArray);

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	}
}
