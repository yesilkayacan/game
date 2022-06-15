#pragma once

#include "glad/glad.h"

namespace Engine
{
	enum class ShaderDataType
	{
		None = 0, Float, Int, Bool
	};

	uint32_t ShaderDataTypeSize(ShaderDataType type);

	GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type);

	class Buffer
	{
	public:
		Buffer() = default;
		virtual ~Buffer() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

	protected:
		uint32_t m_BufferID;
	};
}

//#endif // !ENGINE_BUFFER
