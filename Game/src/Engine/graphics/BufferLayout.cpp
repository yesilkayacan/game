#include "epch.h"
#include "BufferLayout.h"

namespace Engine
{
	BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements)
		:m_Elements(elements)
	{
		CalculateStride();
	}
	void BufferLayout::DefineLayout()
	{
		uint8_t layoutIndex = 0;
		size_t offset = 0;

		for (auto& element : m_Elements)
		{
			glVertexAttribPointer(layoutIndex, element.Amount, Engine::ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized, m_Stride, (void*)offset);
			glEnableVertexAttribArray(layoutIndex);
			layoutIndex ++;
			offset += element.Size;
		}
	}

	void BufferLayout::CalculateStride()
	{
		for (auto& element : m_Elements)
		{
			m_Stride += element.Size;
		}
	}

	BufferElement::BufferElement(std::string name, ShaderDataType type, uint8_t amount)
		:Name(name), Type(type), Amount(amount)
	{
		Size = Amount * Engine::ShaderDataTypeSize(Type);
	}
}
