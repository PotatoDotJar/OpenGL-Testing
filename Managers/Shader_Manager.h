#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "GL/glew.h"
#include "GL/freeglut.h"

namespace Managers
{

	class Shader_Manager
	{

	public:

		Shader_Manager(void);
		~Shader_Manager(void);

		//modify char* to std::string
		void CreateProgram(const std::string& shaderName,
			const std::string& VertexShaderFilename,
			const std::string& FragmentShaderFilename);

		static const GLuint GetShader(const std::string&);

	private:
		//modify char* to std::string
		std::string ReadShader(const std::string& filename);
		//modify char* to std::string
		GLuint CreateShader(GLenum shaderType,
			const std::string& source,
			const std::string& shaderName);

		static std::map<std::string, GLuint> programs;
	};
}


