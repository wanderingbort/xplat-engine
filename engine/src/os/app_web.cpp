#include <emscripten/emscripten.h>

#include "app_internal.h"
#include "app_web.h"

bool app_init_web() {
    return true;
}

void app_run_web (void (*do_frame)()) {
    emscripten_set_main_loop(do_frame, Application_params->framerate_cap, 1);
}

void app_shutdown_web() {
}
