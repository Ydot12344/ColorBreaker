#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<utility>
#include<iostream>
#include "Window.h"
Window w(800, 600);

int main() {

	//init();

	while (!glfwWindowShouldClose(w.getWindow())) {
		char sobaka;
	}

	glfwTerminate();
}