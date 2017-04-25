#include "app.h"

const app::params *Application_params = nullptr;

bool app::init_internal(app::params const *params) {
    Application_params = params;
    m_params = params;

    bool res = true;
    res = res && HOOKS(app)::bind(this);
    res = res && m_display.init(&params->display);
    res = res && m_input.init(&params->input);

    return res;
}

static app *running_app = nullptr;
void do_frame_internal() {
    running_app->m_input.poll();
    running_app->m_display.clear();
    running_app->m_params->on_frame();
    running_app->m_display.swap();
}

void app::run() {
    running_app = this;
    HOOKS(app)::run(do_frame_internal);
    running_app = nullptr;
}

void app::shutdown() {
    m_input.shutdown();
    m_display.shutdown();
    HOOKS(app)::shutdown();
}

app *app::init(params const *params) {
    static app g_the_app;
    bool result = g_the_app.init_internal(params);
    return result ? &g_the_app : nullptr;
}
