#include "input.h"
#include "input_limits.h"
#include <algorithm>
#include <type_traits>
#include "util/platform.h"

#include platform_header(input)

bool Input_key_down[NUM_INPUT_KEYS] = {false};
bool Input_key_hit[NUM_INPUT_KEYS] = {false};


wchar_t Input_pending_unicode[MAX_PENDING_UNICODE] = {0};
size_t Input_pending_unicode_length = 0;

size_t Input_num_pointers = 0;
Input_pointer_state Input_pointer_info[MAX_INPUT_POINTERS];


bool input_init() {
    return platform_call(input_init);
}

void input_poll() {
    std::fill(Input_key_hit, Input_key_hit + NUM_INPUT_KEYS, false);
    platform_call(input_poll);
}

static bool key_check(bool *state, Input_key key, Input_mod mod) {
    size_t index = input_key_ordinal(key);
    if (index >= NUM_INPUT_KEYS) {
        return false;
    }

    bool pressed = state[index];
    if (pressed && mod != Input_mod::ANY) {
        bool is_shift = input_key_down(Input_key::L_SHIFT) || input_key_down(Input_key::R_SHIFT);
        bool is_ctrl = input_key_down(Input_key::L_CTRL) || input_key_down(Input_key::R_CTRL);
        bool is_alt = input_key_down(Input_key::L_ALT) || input_key_down(Input_key::R_ALT);

        switch(mod) {
        case Input_mod::SHIFT:
            pressed = is_shift;
            break;
        case Input_mod::CTRL:
            pressed = is_ctrl;
            break;
        case Input_mod::ALT:
            pressed = is_alt;
            break;
        case Input_mod::NONE:
            pressed = !(is_shift || is_ctrl || is_alt);
            break;
        case Input_mod::ANY:
            // no change
            break;
        }
    }

    return pressed;
}

bool input_key_down(Input_key key, Input_mod  mod) {
    return key_check(Input_key_down, key, mod);
}

bool input_key_hit(Input_key key, Input_mod mod) {
    return key_check(Input_key_hit, key, mod);
}

size_t input_get_pointer_count() {
    return Input_num_pointers;
}

Input_pointer_state const &input_get_pointer_state(size_t pointer_index) {
    static Input_pointer_state Invalid_pointer_state = { -1.0f, -1.0f, false, false };
    if (pointer_index < Input_num_pointers) {
        return Input_pointer_info[pointer_index];
    } else {
        return Invalid_pointer_state;
    }
}

wchar_t const *input_get_pending_unicode(size_t &num_code_points) {
    num_code_points = Input_pending_unicode_length;
    return Input_pending_unicode;
}

void input_clear_pending_unicode() {
    Input_pending_unicode_length = 0;
}

void input_shutdown() {
    platform_call(input_shutdown);
}
