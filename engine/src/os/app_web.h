#if !defined(__APP_WEB_H__)
#define __APP_WEB_H__

class app;
class app_web {
public:
    bool bind(app *app_common);
    void run(void (*do_frame)());

private:
    int m_framerate_cap;
};

#endif //!defined(__APP_WEB_H__)