#if !defined(__INPUT_H__)
#define __INPUT_H__

#include <stddef.h>

class input_params {
public:
    input_params()
    {}

};

enum class Input_key {
    A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
    NUM_1,NUM_2,NUM_3,NUM_4,NUM_5,NUM_6,NUM_7,NUM_8,NUM_9,NUM_0,
    FN_1,FN_2,FN_3,FN_4,FN_5,FN_6,FN_7,FN_8,FN_9,FN_10,FN_11,FN_12,
    TAB, L_SHIFT, R_SHIFT, L_CTRL, R_CTRL, L_ALT, R_ALT, SPACE, ENTER, ESC, BACKSPACE,
    TILDE, DASH, EQUAL, BACK, L_BRACKET, R_BRACKET, BACKSLASH, SEMICOLON, SINGLE_QUOTE, COMMA, PERIOD, FORWARD_SLASH,
    INSERT, DELETE, HOME, END, PG_UP, PG_DOWN, PRINT, PAUSE,
    PAD_1,PAD_2,PAD_3,PAD_4,PAD_5,PAD_6,PAD_7,PAD_8,PAD_9,PAD_0,
    PAD_DIV, PAD_MUL, PAD_SUB, PAD_ADD, PAD_ENTER, PAD_DEL,
    UP, DOWN, LEFT, RIGHT,

    COUNT,
    INVALID
};

enum class Input_mod {
    SHIFT, CTRL, ALT, NONE, ANY
};

struct Input_pointer_state {
    float x;
    float y;
    bool down;
    bool clicked;
};

bool input_init();
void input_poll();

bool input_key_down(Input_key key, Input_mod mod = Input_mod::ANY);
bool input_key_hit(Input_key key, Input_mod mod = Input_mod::ANY);
size_t input_get_pointer_count();
Input_pointer_state const &input_get_pointer_state(size_t pointer_index);

wchar_t const *input_get_pending_unicode(size_t &num_code_points);
void input_clear_pending_unicode();

void input_shutdown();


#endif //!defined(__INPUT_H__)