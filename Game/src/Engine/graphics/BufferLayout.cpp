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

		for (auto& element : m_Elements)
		{
			glVertexAttribPointer(layoutIndex, element.Amount, element.ShaderDataTypeToOpenGLBaseType(), element.Normalized, m_Stride, (void*)0);
			glEnableVertexAttribArray(layoutIndex);
			layoutIndex ++;
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
		Size = Amount * ShaderDataTypeSize();
	}

	uint32_t BufferElement::ShaderDataTypeSize()
	{
		switch (Type)
		{
		case ShaderDataType::Float:    return sizeof(float);
		case ShaderDataType::Int:      return sizeof(int);
		case ShaderDataType::Bool:     return sizeof(bool);
		}

		return 0;
	}

	GLenum BufferElement::ShaderDataTypeToOpenGLBaseType()
	{
		switch (Type)
		{
		case ShaderDataType::Float:    return GL_FLOAT;
		case ShaderDataType::Int:      return GL_INT;
		case ShaderDataType::Bool:     return GL_BOOL;
		}
		return 0;
	}
}
