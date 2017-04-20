#include "engine/os/app.h"
#include <GL/glfw.h>

static void on_gl_ready() {

}

static void on_dimension_change(int width, int height) {
    glViewport(0, 0, width, height);
}

static void do_frame() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int main()
{
    app_params params;
    params.width = 640;
    params.height = 480;
    params.framerate_cap = 60;
    params.on_frame = do_frame;
    params.display.on_gl_ready = on_gl_ready;
    params.display.on_dimension_change = on_dimension_change;

    if (app_init(&params)) {
        app_run();
    }

    app_shutdown();

	return 0;
}