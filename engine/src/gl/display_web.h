#if !defined(__DISPLAY_WEB_H__)
#define __DISPLAY_WEB_H__

class display;
class display_web {
public:
    bool bind(display *common_display);
    bool init();
    void clear();
    void swap();
    void shutdown();

    int m_width;
    int m_height;
};

#endif //!defined(__DISPLAY_WEB_H__)