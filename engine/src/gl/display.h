#if !defined(__DISPLAY_H__)
#define __DISPLAY_H__

#include "util/platform.h"
#include platform_header(display)

DECLARE_HOOKS_START(display)
protected:
    DECLARE_OPTIONAL_HOOK(bool, true, init);
public:
    DECLARE_REQUIRED_HOOK_VOID(clear);
    DECLARE_REQUIRED_HOOK_VOID(swap);
    DECLARE_OPTIONAL_HOOK_VOID(shutdown);
DECLARE_HOOKS_END();

class display : public HOOKS(display) {
public:
    class params {
    public:
        params() 
        {}

        int width;
        int height;
    };

    bool init(params const *params);
    params const *m_params;
};


#endif //!defined(__DISPLAY_H__)