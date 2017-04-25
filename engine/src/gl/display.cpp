#include "display.h"

bool display::init(display::params const *params) {
    m_params = params;
    bool res = true;
    res && HOOKS(display)::bind(this);
    res && HOOKS(display)::init();
    return res;
}
