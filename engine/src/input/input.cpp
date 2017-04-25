#include "input.h"
#include <algorithm>
#include <type_traits>


bool input::init( input::params const *params) {
    m_params = params;
    bool res = true;
    res = res && bind(this);
    res = res && HOOKS(input)::init();
    return res;
}

void input::poll() {
    std::fill(m_key_hit, m_key_hit + NUM_INPUT_KEYS, false);
    HOOKS(input)::poll();
}

bool input::key_check(bool *state, input::key key, input::mod mod) {
    size_t index = key_ordinal(key);
    if (index >= NUM_INPUT_KEYS) {
        return false;
    }

    bool pressed = state[index];
    if (pressed && mod != input::mod::ANY) {
        bool is_shift = key_down(input::key::L_SHIFT) || key_down(input::key::R_SHIFT);
        bool is_ctrl = key_down(input::key::L_CTRL) || key_down(input::key::R_CTRL);
        bool is_alt = key_down(input::key::L_ALT) || key_down(input::key::R_ALT);

        switch(mod) {
        case input::mod::SHIFT:
            pressed = is_shift;
            break;
        case input::mod::CTRL:
            pressed = is_ctrl;
            break;
        case input::mod::ALT:
            pressed = is_alt;
            break;
        case input::mod::NONE:
            pressed = !(is_shift || is_ctrl || is_alt);
            break;
        case input::mod::ANY:
            // no change
            break;
        }
    }

    return pressed;
}

bool input::key_down(input::key key, input::mod  mod) {
    return key_check(m_key_down, key, mod);
}

bool input::key_hit(input::key key, input::mod mod) {
    return key_check(m_key_hit, key, mod);
}

size_t input::get_pointer_count() {
    return m_num_pointers;
}

input::pointer_state const &input::get_pointer_state(size_t pointer_index) {
    static input::pointer_state Invalid_pointer_state = { -1.0f, -1.0f, false, false };
    if (pointer_index < m_num_pointers) {
        return m_pointer_info[pointer_index];
    } else {
        return Invalid_pointer_state;
    }
}

wchar_t const *input::get_pending_unicode(size_t &num_code_points) {
    num_code_points = m_pending_unicode_length;
    return m_pending_unicode;
}

void input::clear_pending_unicode() {
    m_pending_unicode_length = 0;
}
