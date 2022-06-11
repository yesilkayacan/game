#include "epch.h"
#include "VertexArray.h"

#include "glad/glad.h"

namespace Engine
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_VertexArrayID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_VertexArrayID);
	}

	std::shared_ptr<VertexArray> VertexArray::Create()
	{
		return std::make_shared<VertexArray>();
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(m_VertexArrayID);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer, std::shared_ptr<BufferLayout>& layout)
	{
		this->Bind();
		vertexBuffer->Bind();
		layout->DefineLayout();

		m_VertexBuffer = vertexBuffer;
		m_BufferLayout = layout;
	}

	void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		this->Bind();
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}
}
