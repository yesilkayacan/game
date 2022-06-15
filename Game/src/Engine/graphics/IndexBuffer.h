#pragma once

#include "Buffer.h"

namespace Engine
{
	class IndexBuffer : public Buffer
	{
	public:
		IndexBuffer(uint32_t count);
		//IndexBuffer(uint32_t* indices, uint32_t size);
		IndexBuffer(uint32_t* indices, uint32_t size);
		virtual ~IndexBuffer();

		static std::shared_ptr<IndexBuffer> Create(uint32_t* indices, uint32_t size);

		void Bind() const override;
		void Unbind() const override;

		uint32_t GetCount() { return m_Count; };

	private:
		uint32_t m_Count;
	};
}
