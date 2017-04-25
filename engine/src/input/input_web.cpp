#include "input.h"
#include "input_web.h"
#include <GL/glfw.h>

static input::key const Glfw_low_key_map[48] = {
    input::key::SPACE,            // GLFW_KEY_SPACE
    input::key::SINGLE_QUOTE,     // GLFW_KEY_APOSTROPHE
    input::key::COMMA,            // GLFW_KEY_COMMA
    input::key::DASH,             // GLFW_KEY_MINUS
    input::key::PERIOD,           // GLFW_KEY_PERIOD
    input::key::FORWARD_SLASH,    // GLFW_KEY_SLASH
    input::key::NUM_0,            // GLFW_KEY_0
    input::key::NUM_1,            // GLFW_KEY_1
    input::key::NUM_2,            // GLFW_KEY_2
    input::key::NUM_3,            // GLFW_KEY_3
    input::key::NUM_4,            // GLFW_KEY_4
    input::key::NUM_5,            // GLFW_KEY_5
    input::key::NUM_6,            // GLFW_KEY_6
    input::key::NUM_7,            // GLFW_KEY_7
    input::key::NUM_8,            // GLFW_KEY_8
    input::key::NUM_0,            // GLFW_KEY_9
    input::key::SEMICOLON,        // GLFW_KEY_SEMICOLON
    input::key::EQUAL,            // GLFW_KEY_EQUAL
    input::key::A,                // GLFW_KEY_A
    input::key::B,                // GLFW_KEY_B
    input::key::C,                // GLFW_KEY_C
    input::key::D,                // GLFW_KEY_D
    input::key::E,                // GLFW_KEY_E
    input::key::F,                // GLFW_KEY_F
    input::key::G,                // GLFW_KEY_G
    input::key::H,                // GLFW_KEY_H
    input::key::I,                // GLFW_KEY_I
    input::key::J,                // GLFW_KEY_J
    input::key::K,                // GLFW_KEY_K
    input::key::L,                // GLFW_KEY_L
    input::key::M,                // GLFW_KEY_M
    input::key::N,                // GLFW_KEY_N
    input::key::O,                // GLFW_KEY_O
    input::key::P,                // GLFW_KEY_P
    input::key::Q,                // GLFW_KEY_Q
    input::key::R,                // GLFW_KEY_R
    input::key::S,                // GLFW_KEY_S
    input::key::T,                // GLFW_KEY_T
    input::key::U,                // GLFW_KEY_U
    input::key::V,                // GLFW_KEY_V
    input::key::W,                // GLFW_KEY_W
    input::key::X,                // GLFW_KEY_X
    input::key::Y,                // GLFW_KEY_Y
    input::key::Z,                // GLFW_KEY_Z
    input::key::L_BRACKET,        // GLFW_KEY_LEFT_BRACKET
    input::key::BACKSLASH,        // GLFW_KEY_BACKSLASH
    input::key::R_BRACKET,        // GLFW_KEY_RIGHT_BRACKET
    input::key::TILDE,            // GLFW_KEY_GRAVE_ACCENT
};

static input::key const Glfw_high_key_map[GLFW_KEY_MENU - GLFW_KEY_ESC + 1] = {
    input::key::ESC,              //GLFW_KEY_ESC
    input::key::FN_1,             //GLFW_KEY_F1
    input::key::FN_2,             //GLFW_KEY_F2
    input::key::FN_3,             //GLFW_KEY_F3
    input::key::FN_4,             //GLFW_KEY_F4
    input::key::FN_5,             //GLFW_KEY_F5
    input::key::FN_6,             //GLFW_KEY_F6
    input::key::FN_7,             //GLFW_KEY_F7
    input::key::FN_8,             //GLFW_KEY_F8
    input::key::FN_9,             //GLFW_KEY_F9
    input::key::FN_10,            //GLFW_KEY_F10
    input::key::FN_11,            //GLFW_KEY_F11
    input::key::FN_12,            //GLFW_KEY_F12
    input::key::INVALID,          //GLFW_KEY_F13
    input::key::INVALID,          //GLFW_KEY_F14
    input::key::INVALID,          //GLFW_KEY_F15
    input::key::INVALID,          //GLFW_KEY_F16
    input::key::INVALID,          //GLFW_KEY_F17
    input::key::INVALID,          //GLFW_KEY_F18
    input::key::INVALID,          //GLFW_KEY_F19
    input::key::INVALID,          //GLFW_KEY_F20
    input::key::INVALID,          //GLFW_KEY_F21
    input::key::INVALID,          //GLFW_KEY_F22
    input::key::INVALID,          //GLFW_KEY_F23
    input::key::INVALID,          //GLFW_KEY_F24
    input::key::INVALID,          //GLFW_KEY_F25
    input::key::UP,               //GLFW_KEY_UP
    input::key::DOWN,             //GLFW_KEY_DOWN
    input::key::LEFT,             //GLFW_KEY_LEFT
    input::key::RIGHT,            //GLFW_KEY_RIGHT
    input::key::L_SHIFT,          //GLFW_KEY_LEFT_SHIFT
    input::key::R_SHIFT,          //GLFW_KEY_RIGHT_SHIFT
    input::key::L_CTRL,           //GLFW_KEY_LEFT_CONTROL
    input::key::R_CTRL,           //GLFW_KEY_RIGHT_CONTROL
    input::key::L_ALT,            //GLFW_KEY_LEFT_ALT
    input::key::R_ALT,            //GLFW_KEY_RIGHT_ALT
    input::key::TAB,              //GLFW_KEY_TAB
    input::key::ENTER,            //GLFW_KEY_ENTER
    input::key::BACKSPACE,        //GLFW_KEY_BACKSPACE
    input::key::INSERT,           //GLFW_KEY_INSERT
    input::key::DELETE,           //GLFW_KEY_DELETE
    input::key::PG_UP,            //GLFW_KEY_PAGE_UP
    input::key::PG_DOWN,          //GLFW_KEY_PAGE_DOWN
    input::key::HOME,             //GLFW_KEY_HOME
    input::key::END,              //GLFW_KEY_END
    input::key::PAD_0,            //GLFW_KEY_KP_0
    input::key::PAD_1,            //GLFW_KEY_KP_1
    input::key::PAD_2,            //GLFW_KEY_KP_2
    input::key::PAD_3,            //GLFW_KEY_KP_3
    input::key::PAD_4,            //GLFW_KEY_KP_4
    input::key::PAD_5,            //GLFW_KEY_KP_5
    input::key::PAD_6,            //GLFW_KEY_KP_6
    input::key::PAD_7,            //GLFW_KEY_KP_7
    input::key::PAD_8,            //GLFW_KEY_KP_8
    input::key::PAD_9,            //GLFW_KEY_KP_9
    input::key::PAD_DIV,          //GLFW_KEY_KP_DIVIDE
    input::key::PAD_MUL,          //GLFW_KEY_KP_MULTIPLY
    input::key::PAD_SUB,          //GLFW_KEY_KP_SUBTRACT
    input::key::PAD_ADD,          //GLFW_KEY_KP_ADD
    input::key::PAD_DEL,          //GLFW_KEY_KP_DECIMAL
    input::key::INVALID,          //GLFW_KEY_KP_EQUAL
    input::key::PAD_ENTER,        //GLFW_KEY_KP_ENTER
    input::key::INVALID,          //GLFW_KEY_KP_NUM_LOCK
    input::key::INVALID,          //GLFW_KEY_CAPS_LOCK
    input::key::INVALID,          //GLFW_KEY_SCROLL_LOCK
    input::key::PAUSE,            //GLFW_KEY_PAUSE
    input::key::INVALID,          //GLFW_KEY_LEFT_SUPER
    input::key::INVALID,          //GLFW_KEY_RIGHT_SUPER
    input::key::INVALID,          //GLFW_KEY_MENU
};

static input_web *gs_input = nullptr;
static void key_callback(int key, int action) {
    gs_input->key_cb(key,action);
}
static void char_callback(int unicode_point, int action) {
    gs_input->char_cb(unicode_point, action);
}
static void mouse_button_callback(int button, int action) {
    gs_input->mouse_cb(button, action);
}

bool input_web::bind(input *input_common) {
    m_input_common = input_common;
    return true;
}

bool input_web::init() {
    bool res = true;

    m_input_common->m_num_pointers = 1;

    gs_input = this;
    glfwSetMouseButtonCallback(mouse_button_callback);
    glfwSetKeyCallback(key_callback);
    glfwSetCharCallback(char_callback);

    return res;
}

void input_web::poll() {
    // poll os events and deliver them
    glfwPollEvents();
    
    int x, y;
    glfwGetMousePos(&x, &y);
    m_input_common->m_pointer_info[0].x = (float)x;
    m_input_common->m_pointer_info[0].y = (float)y;
}

void input_web::key_cb(int key, int action) {
    input::key mapped_key = input::key::INVALID;
    if (key >= GLFW_KEY_SPACE && key < GLFW_KEY_SPACE + 48) {
        mapped_key = Glfw_low_key_map[key - GLFW_KEY_SPACE];
    } else if (key >= GLFW_KEY_ESC && key <= GLFW_KEY_MENU) {
        mapped_key = Glfw_high_key_map[key - GLFW_KEY_ESC];
    }

    if (mapped_key != input::key::INVALID) {
        size_t ordinal = input::key_ordinal(mapped_key);
        m_input_common->m_key_down[ordinal] = (action != GLFW_RELEASE);
        m_input_common->m_key_hit[ordinal] |= (action == GLFW_PRESS);
    }
}

void input_web::char_cb(int unicode_point, int action) {
    if (action == GLFW_PRESS && m_input_common->m_pending_unicode_length < input::MAX_PENDING_UNICODE) {
        m_input_common->m_pending_unicode[m_input_common->m_pending_unicode_length++] = static_cast<wchar_t>(unicode_point);
    }
}

void input_web::mouse_cb(int button, int action) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        m_input_common->m_pointer_info[0].down = (action != GLFW_RELEASE);
        m_input_common->m_pointer_info[0].clicked |= (action == GLFW_PRESS);
    }
}
