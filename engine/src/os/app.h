#if !defined(__APP_H__)
#define __APP_H__ 

#include "gl/display.h"

class app_params {
public:
    app_params() 
    {}

    typedef void (*on_frame_cb)();

    int width;
    int height;
    char const *title;
    int framerate_cap;
    on_frame_cb on_frame;

    // other major systems
    display_params display;
    input_params input;
};


bool app_init(const app_params *params);
void app_run();
void app_shutdown();

#endif //!defined(__APP_H__)