#include "app.h"

#if defined(__WEB__)
    #include "app_web.h"
#else
    #error("Unknown Platform");
#endif

const app_params *Application_params = nullptr;

bool app_init(const app_params *params) {
    Application_params = params;
    #if defined(__WEB__)
        return app_init_web();
    #else
        #error("Unknown Platform");
    #endif

    params->display.on_gl_ready();
	params->display.on_dimension_change(params->width, params->height);
}

void app_run() {
    #if defined(__WEB__)
        app_run_web();
    #else
        #error("Unknown Platform");
    #endif
}

void app_shutdown() {
    #if defined(__WEB__)
        app_shutdown_web();
    #else
        #error("Unknown Platform");
    #endif
}
