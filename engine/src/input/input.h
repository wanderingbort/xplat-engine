#if !defined(__INPUT_H__)
#define __INPUT_H__

#include <stddef.h>
#include <type_traits>

#include "util/platform.h"
#include platform_header(input)

DECLARE_HOOKS_START(input)
    DECLARE_OPTIONAL_HOOK(bool, true, init);
    DECLARE_OPTIONAL_HOOK_VOID(poll);
    DECLARE_OPTIONAL_HOOK_VOID(shutdown);
DECLARE_HOOKS_END();

class input : public HOOKS(input) {
public:
    class params {
    public:
        params() 
        {}
    };

    bool init(params const *params);
    params const *m_params;

    void poll();

    enum class key {
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

    enum class mod {
        SHIFT, CTRL, ALT, NONE, ANY
    };

    struct pointer_state {
        float x;
        float y;
        bool down;
        bool clicked;
    };


    bool key_down(key, mod mod = mod::ANY);
    bool key_hit(key, mod mod = mod::ANY);
    size_t get_pointer_count();
    pointer_state const &get_pointer_state(size_t pointer_index);

    wchar_t const *get_pending_unicode(size_t &num_code_points);
    void clear_pending_unicode();

protected:
    friend PLATFORM_CLASS(input);

    static size_t key_ordinal(key value) {
        return static_cast<std::underlying_type<key>::type>(value);
    }

    static size_t const NUM_INPUT_KEYS = static_cast<std::underlying_type<key>::type>(key::COUNT);
    static size_t const MAX_PENDING_UNICODE = 1024;
    static size_t const MAX_INPUT_POINTERS = 4;

    bool m_key_down[NUM_INPUT_KEYS];
    bool m_key_hit[NUM_INPUT_KEYS];

    wchar_t m_pending_unicode[MAX_PENDING_UNICODE];
    size_t m_pending_unicode_length;

    size_t m_num_pointers;
    pointer_state m_pointer_info[MAX_INPUT_POINTERS];

    private:
    bool key_check(bool *state, key, mod mod);
};



#endif //!defined(__INPUT_H__)