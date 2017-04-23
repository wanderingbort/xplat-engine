#include "os/app.h"
#include "input/input.h"

#include <stdio.h>
#include <wchar.h>

static void do_frame() {
}

int main()
{
    app_params params;
    params.display.width = 640;
    params.display.height = 480;
    params.framerate_cap = 0;
    params.on_frame = do_frame;

    if (app_init(&params)) {
        app_run();
    }

    app_shutdown();

	return 0;
}