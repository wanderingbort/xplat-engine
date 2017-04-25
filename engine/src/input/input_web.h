#if !defined(__INPUT_WEB_H__)
#define __INPUT_WEB_H__

class input;
class input_web {
public:
    bool bind(input *input_common);
    bool init();
    void poll();

    void key_cb(int,int);
    void mouse_cb(int,int);
    void char_cb(int,int);

private:
    input *m_input_common;
};

#endif // !defined(__INPUT_WEB_H__)