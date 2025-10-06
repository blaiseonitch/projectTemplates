#include <iostream>
#include "test.hpp"
#include "GLFW/glfw3.h"
#include "blaze.hpp"

int main(){
	glfwInit();

	GLFWwindow *window = glfwCreateWindow(840, 400, "Hello world", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

