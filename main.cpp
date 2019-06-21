#pragma once
#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"


using namespace Core;
int main(int argc, char** argv) {

	Core::WindowInfo window(std::string("in2gpu OpenGL Beginner Tutorial"), 400, 200, 800, 600, true);
	Core::ContextInfo context(4, 5, true);
	Core::FramebufferInfo frameBufferInfo(true, true, true, true);

	Core::Init::Init_GLUT::init(window, context, frameBufferInfo);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	Core::Init::Init_GLUT::run();

	delete scene;
	return 0;
}
