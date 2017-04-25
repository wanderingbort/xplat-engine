#include <emscripten/emscripten.h>

#include "time_web.h"

uint64_t time_web::now_us () {
    double now = emscripten_get_now();
    return static_cast<uint64_t>(now * 1000.0);
}
