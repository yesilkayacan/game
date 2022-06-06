#pragma once

namespace Engine
{
	class IndexBuffer
	{
	public:
		IndexBuffer(uint32_t size);
		IndexBuffer(uint32_t* indices, uint32_t size);
		virtual ~IndexBuffer();

		static std::shared_ptr<IndexBuffer> Create(uint32_t* indices, uint32_t size);

		void Bind() const;
		void Unbind() const;

	private:
		uint32_t m_BufferID;
	};
}
