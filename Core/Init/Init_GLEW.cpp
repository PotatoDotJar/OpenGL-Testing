#include "Init_GLEW.h"
using namespace Core;
using namespace Core::Init;

void Init_GLEW::Init() {

	glewExperimental = true;
	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW: Initialize" << std::endl;
	}

	if (glewIsSupported("GL_VERSION_3_3"))
	{
		std::cout << "GLEW GL_VERSION_3_3 is 3.3\n ";
	}
	else
	{
		std::cout << " GLEW GL_VERSION_3_3 not supported\n ";
	}
}