#include "time.h"

bool time::init(time::params const *params) {
    m_params = params;
    m_frame_us = 0ULL;
    m_frame_ms = 0.0;
    m_frame_s = 0.0;
    m_frame_number = 0ULL;
    bind(this);
    m_previous_now_us = now_us();

    return true;
}

void time::tick_frame() {
    uint64_t now = now_us();
    m_frame_us = now - m_previous_now_us;
    m_frame_ms = static_cast<double>(m_frame_us) / 1000.0;
    m_frame_s = static_cast<double>(m_frame_us) / 1000000.0;
    m_frame_number += 1;
    m_previous_now_us = now;
}

