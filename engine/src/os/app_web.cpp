#include <stdlib.h>
#include <stdio.h>
#include <GL/glfw.h>
#include <emscripten/emscripten.h>

#include "app_web.h"

bool app_init_web() {
    if (glfwInit() != GL_TRUE) {
		printf("glfwInit() failed\n");
		return false;
	}

	if (glfwOpenWindow(Application_params->width, Application_params->height, 8, 8, 8, 8, 16, 0, GLFW_WINDOW) != GL_TRUE) {
		printf("glfwOpenWindow() failed\n");
    	return false;
    }

    return true;
}

static void do_frame() {
    Application_params->on_frame();
    glfwSwapBuffers();
}

void app_run_web() {
    emscripten_set_main_loop(do_frame, Application_params->framerate_cap, 1);
}

void app_shutdown_web() {
    glfwTerminate();
}
