#if !defined(__DISPLAY_H__)
#define __DISPLAY_H__

class display_params {
public:
    display_params()
    {}

    int width;
    int height;
};

bool display_init();
void display_clear();
void display_swap();
void display_shutdown();

#endif //!defined(__DISPLAY_H__)