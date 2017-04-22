#include <stdlib.h>
#include <stdio.h>
#include <GL/glfw.h>

#include "display.h"
#include "os/app_internal.h"

bool display_init_web() {
    if (glfwInit() != GL_TRUE) {
		printf("glfwInit() failed\n");
		return false;
	}

	if (glfwOpenWindow(Application_params->width, Application_params->height, 8, 8, 8, 8, 16, 0, GLFW_WINDOW) != GL_TRUE) {
		printf("glfwOpenWindow() failed\n");
    	return false;
    }

    // need to set up some sort callback for when the canvas changes dimensions
    glViewport(0, 0, Application_params->width, Application_params->height);

    return true;
}

void display_clear_web() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display_swap_web() {
    glfwSwapBuffers();
}

void display_shutdown_web() {
    glfwTerminate();
}
