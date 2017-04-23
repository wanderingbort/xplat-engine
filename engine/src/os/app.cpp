#include "app.h"
#include "input/input.h"
#include "gl/display.h"
#include "util/platform.h"

#include platform_header(app)

const app_params *Application_params = nullptr;

bool app_init(const app_params *params) {
    Application_params = params;

    bool res = true;
    res = res && platform_call(app_init);
    res = res && display_init();
    res = res && input_init();

    return res;
}

static void do_frame() {
    input_poll();
    display_clear();
    Application_params->on_frame();
    display_swap();
}

void app_run() {
    platform_call(app_run, do_frame);
}

void app_shutdown() {
    input_shutdown();
    display_shutdown();
    platform_call(app_shutdown);
}
