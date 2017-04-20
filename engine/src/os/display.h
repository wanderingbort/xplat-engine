#if !defined(__DISPLAY_H__)
#define __DISPLAY_H__

class display_params {
public:
    display_params()
        :on_gl_ready(nullptr)
        ,on_dimension_change(nullptr)
    {}

    typedef void (*dimension_cb)(int width, int height);
    typedef void (*gl_ready_cb)();

    gl_ready_cb on_gl_ready;    
    dimension_cb on_dimension_change;
};


#endif //!defined(__DISPLAY_H__)