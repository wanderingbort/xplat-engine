#include "app.h"
#include "input/input.h"
#include "gl/display.h"

const app::params *Application_params = nullptr;

bool app::init_internal(app::params const *params) {
    Application_params = params;
    m_params = params;

    bool res = true;
    res = res && HOOKS(app)::bind(this);
    res = res && display_init();
    res = res && input_init();

    return res;
}

static app *running_app = nullptr;
void do_frame_internal() {
    input_poll();
    display_clear();
    running_app->m_params->on_frame();
    display_swap();
}

void app::run() {
    running_app = this;
    HOOKS(app)::run(do_frame_internal);
    running_app = nullptr;
}

void app::shutdown() {
    input_shutdown();
    display_shutdown();
    HOOKS(app)::shutdown();
}

app *app::init(params const *params) {
    static app g_the_app;
    g_the_app.init_internal(params);
    return &g_the_app;
}
