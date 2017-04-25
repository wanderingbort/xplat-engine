#include "os/app.h"
#include "input/input.h"

#include <stdio.h>
#include <wchar.h>

app *the_app = nullptr;

static void do_frame() {
    
}

int main()
{
    app::params params;
    params.display.width = 640;
    params.display.height = 480;
    params.framerate_cap = 0;
    params.on_frame = do_frame;

    printf("INITIALIZING\n");
    the_app = app::init(&params);
    if (the_app != nullptr) {
        printf("STARTING MAIN LOOP\n");
        the_app->run();
    }

    printf("SHUTTING DOWN\n");
    the_app->shutdown();

	return 0;
}