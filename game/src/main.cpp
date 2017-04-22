#include "os/app.h"
#include <GL/glfw.h>

static void on_gl_ready() {

}

static void on_dimension_change(int , int ) {
    
}

static void do_frame() {
    
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