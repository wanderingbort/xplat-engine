#include <emscripten/emscripten.h>

#include "app.h"
#include "app_web.h"

bool app_web::bind(app *common_app) {
    m_framerate_cap = common_app->m_params->framerate_cap;
    return true;
}

void app_web::run (void (*do_frame)()) {
    emscripten_set_main_loop(do_frame, m_framerate_cap, 1);
}
