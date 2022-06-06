#pragma once

namespace Engine
{
	class VertexBuffer
	{
	public:
		VertexBuffer(uint32_t size);
		VertexBuffer(float* vertices, uint32_t size);
		virtual ~VertexBuffer();

		static std::shared_ptr<VertexBuffer> Create(float* vertices, uint32_t size);

		void Bind() const;
		void Unbind() const;

		void SetData(const void* data, uint32_t size);

	private:
		uint32_t m_BufferID;
	};
}
