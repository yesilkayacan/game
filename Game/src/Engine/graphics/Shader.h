#pragma once

#include <string>

namespace Engine
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		static std::shared_ptr<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}


