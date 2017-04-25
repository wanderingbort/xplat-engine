#include <stdlib.h>
#include <stdio.h>
#include <GL/glfw.h>

#include "display.h"
#include "display_web.h"

bool display_web::bind(display *common_display) {
    m_width = common_display->m_params->width;
    m_height = common_display->m_params->width;
    return true;
}

bool display_web::init() {
    if (glfwInit() != GL_TRUE) {
		printf("glfwInit() failed\n");
		return false;
	}

	if (glfwOpenWindow(m_width, m_height, 8, 8, 8, 8, 16, 0, GLFW_WINDOW) != GL_TRUE) {
		printf("glfwOpenWindow() failed\n");
    	return false;
    }

    // need to set up some sort callback for when the canvas changes dimensions
    glViewport(0, 0, m_width, m_height);

    return true;
}

void display_web::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void display_web::swap() {
    glfwSwapBuffers();
}

void display_web::shutdown() {
    glfwTerminate();
}
