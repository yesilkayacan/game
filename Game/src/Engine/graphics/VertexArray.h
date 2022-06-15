#pragma once

#include <memory>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferLayout.h"

namespace Engine
{
	class VertexArray
	{
	public:
		VertexArray();
		virtual ~VertexArray();
		
		static std::shared_ptr<VertexArray> Create();

		void Bind() const;
		void Unbind() const;
		
		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer, std::shared_ptr<BufferLayout>& layout);
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

		std::shared_ptr<IndexBuffer> GetIndexBuffer() { return m_IndexBuffer; };

	private:
		uint32_t m_VertexArrayID;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<BufferLayout> m_BufferLayout;
	};
}
