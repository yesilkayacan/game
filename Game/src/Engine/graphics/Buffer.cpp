#include "epch.h"
#include "Buffer.h"

namespace Engine
{
	uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return sizeof(float);
		case ShaderDataType::Int:      return sizeof(int);
		case ShaderDataType::Bool:     return sizeof(bool);
		}
		return 0;
	};

	GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:    return GL_FLOAT;
		case ShaderDataType::Int:      return GL_INT;
		case ShaderDataType::Bool:     return GL_BOOL;
		}
		return 0;
	};
}