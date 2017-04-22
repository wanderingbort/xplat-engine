#include "display.h"
#include "os/app_internal.h"
#include "util/platform.h"
#include platform_header(display)

bool display_init() {
    bool res = true;
    res && platform_call(display_init);
    return res;
}

void display_clear() {
    platform_call(display_clear);
}

void display_swap() {
    platform_call(display_swap);
}

void display_shutdown() {
    platform_call(display_shutdown);
}
