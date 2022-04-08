#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>

class Window {
public:
	size_t height, width;
	Window(size_t w, size_t h) : width(w), height(h) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glfwWindowHint(GLFW_SAMPLES, 4);
		glEnable(GL_MULTISAMPLE);
		window = glfwCreateWindow(width, height, "ColorBreaker", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		// Setup cursore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		if (glfwRawMouseMotionSupported()) // for smooth movement of cursor
			glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

		glewExperimental = GL_TRUE;
		glewInit();

		glViewport(0, 0, width, height);

	}
	GLFWwindow* getWindow() {
		return window;
	}

	void setViewPort(size_t w, size_t h) {
		glViewport(0, 0, w, h);
	}

private:
	GLFWwindow* window = nullptr;

};