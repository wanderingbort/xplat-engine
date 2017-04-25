#if !defined(__APP_H__)
#define __APP_H__ 

#include "time.h"
#include "gl/display.h"
#include "input/input.h"

#include "util/platform.h"
#include platform_header(app)


typedef void (*do_frame_callback)();

DECLARE_HOOKS_START(app)
    DECLARE_REQUIRED_HOOK_VOID(run, do_frame_callback);
    DECLARE_OPTIONAL_HOOK_VOID(shutdown);
DECLARE_HOOKS_END();

class app : HOOKS(app) {
public:
    class params {
    public:
        params() 
        {}

        typedef void (*on_frame_cb)();

        char const *title;
        on_frame_cb on_frame;
        int framerate_cap;

        // other major systems
        time::params time;
        display::params display;
        input::params input;
    };

    static app *init(params const *params);
    void run();
    void shutdown();


    params const *m_params;
    time m_time;
    display m_display;
    input m_input;

private:
    app(){};
    bool init_internal(params const *params);
};

#endif //!defined(__APP_H__)