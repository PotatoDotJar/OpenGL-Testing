//GlutInit.cpp
#include "Init_GLUT.h"
#include "IListener.h"

using namespace Core::Init;

Core::IListener* Init_GLUT::listener = NULL;
Core::WindowInfo Init_GLUT::windowInformation;

void Init_GLUT::init(const Core::WindowInfo& windowInfo,
	const Core::ContextInfo& contextInfo,
	const Core::FramebufferInfo& framebufferInfo)
{
	int fakeargc = 1;
	char* fakeargv[] = { "fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core)
	{
		glutInitContextVersion(contextInfo.major_version, contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(framebufferInfo.flags);
	glutInitWindowPosition(windowInfo.position_x, windowInfo.position_y);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name.c_str());
	std::cout << "GLUT:initialized" << std::endl;

	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	Core::Init::Init_GLEW::Init();

	windowInformation = windowInfo;

	//cleanup
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);


	printOpenGLInfo(windowInfo, contextInfo);

}

void Init_GLUT::run() {

	std::cout << "GLUT:\t Start Running  " << std::endl;
	glutMainLoop();
}


void Init_GLUT::close() {


	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init_GLUT::idleCallback(void) {

	glutPostRedisplay();
}

void Init_GLUT::displayCallback() {
	if (listener)
	{
		listener->notifyBeginFrame();
		listener->notifyDisplayFrame();

		glutSwapBuffers();

		listener->notifyEndFrame();
	}
}

void Init_GLUT::reshapeCallback(int width, int height) {
	if (windowInformation.isReshapable == true)
	{
		if (listener)
		{
			listener->notifyReshape(width,
				height,
				windowInformation.width,
				windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
	}
}

void Init_GLUT::setListener(Core::IListener*& iListener)
{
	listener = iListener;
}

void Init_GLUT::closeCallback() {

	close();
}

void Init_GLUT::enterFullscreen() {

	glutFullScreen();
}

void Init_GLUT::exitFullscreen() {

	glutLeaveFullScreen();
}

void Init_GLUT::printOpenGLInfo(const Core::WindowInfo& windowInfo, const Core::ContextInfo& contextInfo) {

	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "*******************************************************************************" << std::endl;

	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
	std::cout << "GLUT:\tInitial window is '" << windowInfo.name << "', with dimensions (" << windowInfo.width
		<< "X" << windowInfo.height;
	std::cout << ") starts at (" << windowInfo.position_x << "X" << windowInfo.position_y;
	std::cout << ") and " << ((windowInfo.isReshapable) ? "is" : "is not ") << " redimensionable" << std::endl;
	std::cout << "GLUT:\tInitial Framebuffer contains double buffers for" << std::endl;

	std::cout << "GLUT:\t OpenGL context is " << contextInfo.major_version << "." << contextInfo.minor_version;
	std::cout << " and profile is " << ((contextInfo.core) ? "core" : "compatibility") << std::endl;

	std::cout << "*****************************************************************" << std::endl;
}
