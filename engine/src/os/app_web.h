#if !defined(__APP_WEB_H__)
#define __APP_WEB_H__

bool app_init_web();
void app_run_web(void (*do_frame)());
void app_shutdown_web();

#endif //!defined(__APP_WEB_H__)