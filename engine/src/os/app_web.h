#if !defined(__APP_WEB_H__)
#define __APP_WEB_H__

#include "app.h"

extern app_params const *Application_params;

bool app_init_web();
void app_run_web();
void app_shutdown_web();

#endif //!defined(__APP_WEB_H__)