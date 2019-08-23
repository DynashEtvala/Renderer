#include "context.h"

// system headers
#include <iostream>

// library headers
#include "glew/GL/glew.h"
#include "glfw/glfw3.h"

using std::cout;
using std::endl;

bool context::init(int width, int height, const char * title)
{
	glfwInit();

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	glfwMakeContextCurrent(window);

	glewInit();

	cout << "OpenGL Version: " << (const char *)glGetString(GL_VERSION) << endl;
	cout << "Renderer: " << (const char *)glGetString(GL_RENDERER) << endl;
	cout << "Vendor: " << (const char *)glGetString(GL_VENDOR) << endl;
	cout << "GLSL: " << (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

	return true;
}

void context::tick()
{
	glfwPollEvents();
	glfwSwapBuffers(window);
}

void context::term()
{
	glfwDestroyWindow(window);
	glfwTerminate();

	window = nullptr;
}

void context::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool context::shouldClose() const
{
	return glfwWindowShouldClose(window);
}