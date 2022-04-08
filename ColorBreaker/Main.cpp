#define GLEW_STATIC

// GLEW
#include<GL/glew.h>

// GLFW
#include<GLFW/glfw3.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Std
#include<utility>
#include<iostream>
#include<set>

// Custom
#include "Window.h"
#include"Camera.h"

using vec3 = glm::vec3;

Window w(800, 600);
Camera camera(vec3(0.f, 0.f, 3.f), vec3(0.f, 1.f, 0.f));
bool keys[1024];
double deltaTime;
double lastTime, currentTime;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keys[key] = false;
	}
	 

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(w.getWindow(), GLFW_TRUE);

	if (keys[GLFW_KEY_A]) {
		camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
	}
	if (keys[GLFW_KEY_S]) {
		camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
	}
	if (keys[GLFW_KEY_D]) {
		camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
	}
	if (keys[GLFW_KEY_W]) {
		camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
	}
}

void init() {
	glfwSetKeyCallback(w.getWindow(), key_callback);
}



int main() {

	lastTime = glfwGetTime();

	init();

	while (!glfwWindowShouldClose(w.getWindow())) {
		glfwPollEvents();

		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		auto pos = camera.getPosition();
		std::cout << "Pos: " << "X: " << pos.x << " Y: " << pos.y << " Z: " << pos.z << '\n';

		glfwSwapBuffers(w.getWindow());
	}
	 
	glfwTerminate();
}