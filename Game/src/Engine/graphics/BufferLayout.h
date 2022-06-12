#pragma once

#include "glad/glad.h"
#include "Buffer.h"

namespace Engine
{
	class BufferElement
	{
	public:
		std::string Name;
		ShaderDataType Type;
		uint8_t Amount;
		size_t Size;
		bool Normalized = false;

	public:
		BufferElement(std::string name, ShaderDataType type, uint8_t amount);
	};

	class BufferLayout
	{
	public:
		BufferLayout(std::initializer_list<BufferElement> elements);

		void DefineLayout();

	private:
		std::vector<BufferElement> m_Elements;
		size_t m_Stride = 0;

	private:
		void CalculateStride();
	};
}
