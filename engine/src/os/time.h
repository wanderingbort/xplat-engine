#if !defined(__TIME_H__)
#define __TIME_H__

#include "util/platform.h"
#include platform_header(time)

#include <cstdint>

DECLARE_HOOKS_START(time)
    DECLARE_REQUIRED_HOOK(uint64_t, now_us);
DECLARE_HOOKS_END();

class time : public HOOKS(time) {
public:
    class params {
    public:
        params() 
        {}

        uint64_t fixed_tick_ms;
    };

    bool init(params const *pararms);
    void tick_frame();

    uint64_t m_frame_us;
    double m_frame_ms;
    double m_frame_s;
    uint64_t m_frame_number;
    params const *m_params;

private:
    uint64_t m_previous_now_us;
};


#endif //!defined(__TIME_H__)