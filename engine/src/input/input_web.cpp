#include "input_web.h"
#include "input_internal.h"
#include <GL/glfw.h>

static Input_key const Glfw_low_key_map[48] = {
    Input_key::SPACE,            // GLFW_KEY_SPACE
    Input_key::SINGLE_QUOTE,     // GLFW_KEY_APOSTROPHE
    Input_key::COMMA,            // GLFW_KEY_COMMA
    Input_key::DASH,             // GLFW_KEY_MINUS
    Input_key::PERIOD,           // GLFW_KEY_PERIOD
    Input_key::FORWARD_SLASH,    // GLFW_KEY_SLASH
    Input_key::NUM_0,            // GLFW_KEY_0
    Input_key::NUM_1,            // GLFW_KEY_1
    Input_key::NUM_2,            // GLFW_KEY_2
    Input_key::NUM_3,            // GLFW_KEY_3
    Input_key::NUM_4,            // GLFW_KEY_4
    Input_key::NUM_5,            // GLFW_KEY_5
    Input_key::NUM_6,            // GLFW_KEY_6
    Input_key::NUM_7,            // GLFW_KEY_7
    Input_key::NUM_8,            // GLFW_KEY_8
    Input_key::NUM_0,            // GLFW_KEY_9
    Input_key::SEMICOLON,        // GLFW_KEY_SEMICOLON
    Input_key::EQUAL,            // GLFW_KEY_EQUAL
    Input_key::A,                // GLFW_KEY_A
    Input_key::B,                // GLFW_KEY_B
    Input_key::C,                // GLFW_KEY_C
    Input_key::D,                // GLFW_KEY_D
    Input_key::E,                // GLFW_KEY_E
    Input_key::F,                // GLFW_KEY_F
    Input_key::G,                // GLFW_KEY_G
    Input_key::H,                // GLFW_KEY_H
    Input_key::I,                // GLFW_KEY_I
    Input_key::J,                // GLFW_KEY_J
    Input_key::K,                // GLFW_KEY_K
    Input_key::L,                // GLFW_KEY_L
    Input_key::M,                // GLFW_KEY_M
    Input_key::N,                // GLFW_KEY_N
    Input_key::O,                // GLFW_KEY_O
    Input_key::P,                // GLFW_KEY_P
    Input_key::Q,                // GLFW_KEY_Q
    Input_key::R,                // GLFW_KEY_R
    Input_key::S,                // GLFW_KEY_S
    Input_key::T,                // GLFW_KEY_T
    Input_key::U,                // GLFW_KEY_U
    Input_key::V,                // GLFW_KEY_V
    Input_key::W,                // GLFW_KEY_W
    Input_key::X,                // GLFW_KEY_X
    Input_key::Y,                // GLFW_KEY_Y
    Input_key::Z,                // GLFW_KEY_Z
    Input_key::L_BRACKET,        // GLFW_KEY_LEFT_BRACKET
    Input_key::BACKSLASH,        // GLFW_KEY_BACKSLASH
    Input_key::R_BRACKET,        // GLFW_KEY_RIGHT_BRACKET
    Input_key::TILDE,            // GLFW_KEY_GRAVE_ACCENT
};

static Input_key const Glfw_high_key_map[GLFW_KEY_MENU - GLFW_KEY_ESC + 1] = {
    Input_key::ESC,              //GLFW_KEY_ESC
    Input_key::FN_1,             //GLFW_KEY_F1
    Input_key::FN_2,             //GLFW_KEY_F2
    Input_key::FN_3,             //GLFW_KEY_F3
    Input_key::FN_4,             //GLFW_KEY_F4
    Input_key::FN_5,             //GLFW_KEY_F5
    Input_key::FN_6,             //GLFW_KEY_F6
    Input_key::FN_7,             //GLFW_KEY_F7
    Input_key::FN_8,             //GLFW_KEY_F8
    Input_key::FN_9,             //GLFW_KEY_F9
    Input_key::FN_10,            //GLFW_KEY_F10
    Input_key::FN_11,            //GLFW_KEY_F11
    Input_key::FN_12,            //GLFW_KEY_F12
    Input_key::INVALID,          //GLFW_KEY_F13
    Input_key::INVALID,          //GLFW_KEY_F14
    Input_key::INVALID,          //GLFW_KEY_F15
    Input_key::INVALID,          //GLFW_KEY_F16
    Input_key::INVALID,          //GLFW_KEY_F17
    Input_key::INVALID,          //GLFW_KEY_F18
    Input_key::INVALID,          //GLFW_KEY_F19
    Input_key::INVALID,          //GLFW_KEY_F20
    Input_key::INVALID,          //GLFW_KEY_F21
    Input_key::INVALID,          //GLFW_KEY_F22
    Input_key::INVALID,          //GLFW_KEY_F23
    Input_key::INVALID,          //GLFW_KEY_F24
    Input_key::INVALID,          //GLFW_KEY_F25
    Input_key::UP,               //GLFW_KEY_UP
    Input_key::DOWN,             //GLFW_KEY_DOWN
    Input_key::LEFT,             //GLFW_KEY_LEFT
    Input_key::RIGHT,            //GLFW_KEY_RIGHT
    Input_key::L_SHIFT,          //GLFW_KEY_LEFT_SHIFT
    Input_key::R_SHIFT,          //GLFW_KEY_RIGHT_SHIFT
    Input_key::L_CTRL,           //GLFW_KEY_LEFT_CONTROL
    Input_key::R_CTRL,           //GLFW_KEY_RIGHT_CONTROL
    Input_key::L_ALT,            //GLFW_KEY_LEFT_ALT
    Input_key::R_ALT,            //GLFW_KEY_RIGHT_ALT
    Input_key::TAB,              //GLFW_KEY_TAB
    Input_key::ENTER,            //GLFW_KEY_ENTER
    Input_key::BACKSPACE,        //GLFW_KEY_BACKSPACE
    Input_key::INSERT,           //GLFW_KEY_INSERT
    Input_key::DELETE,           //GLFW_KEY_DELETE
    Input_key::PG_UP,            //GLFW_KEY_PAGE_UP
    Input_key::PG_DOWN,          //GLFW_KEY_PAGE_DOWN
    Input_key::HOME,             //GLFW_KEY_HOME
    Input_key::END,              //GLFW_KEY_END
    Input_key::PAD_0,            //GLFW_KEY_KP_0
    Input_key::PAD_1,            //GLFW_KEY_KP_1
    Input_key::PAD_2,            //GLFW_KEY_KP_2
    Input_key::PAD_3,            //GLFW_KEY_KP_3
    Input_key::PAD_4,            //GLFW_KEY_KP_4
    Input_key::PAD_5,            //GLFW_KEY_KP_5
    Input_key::PAD_6,            //GLFW_KEY_KP_6
    Input_key::PAD_7,            //GLFW_KEY_KP_7
    Input_key::PAD_8,            //GLFW_KEY_KP_8
    Input_key::PAD_9,            //GLFW_KEY_KP_9
    Input_key::PAD_DIV,          //GLFW_KEY_KP_DIVIDE
    Input_key::PAD_MUL,          //GLFW_KEY_KP_MULTIPLY
    Input_key::PAD_SUB,          //GLFW_KEY_KP_SUBTRACT
    Input_key::PAD_ADD,          //GLFW_KEY_KP_ADD
    Input_key::PAD_DEL,          //GLFW_KEY_KP_DECIMAL
    Input_key::INVALID,          //GLFW_KEY_KP_EQUAL
    Input_key::PAD_ENTER,        //GLFW_KEY_KP_ENTER
    Input_key::INVALID,          //GLFW_KEY_KP_NUM_LOCK
    Input_key::INVALID,          //GLFW_KEY_CAPS_LOCK
    Input_key::INVALID,          //GLFW_KEY_SCROLL_LOCK
    Input_key::PAUSE,            //GLFW_KEY_PAUSE
    Input_key::INVALID,          //GLFW_KEY_LEFT_SUPER
    Input_key::INVALID,          //GLFW_KEY_RIGHT_SUPER
    Input_key::INVALID,          //GLFW_KEY_MENU
};

static void key_callback(int key, int action)
{
    Input_key mapped_key = Input_key::INVALID;
    if (key >= GLFW_KEY_SPACE && key < GLFW_KEY_SPACE + 48) {
        mapped_key = Glfw_low_key_map[key - GLFW_KEY_SPACE];
    } else if (key >= GLFW_KEY_ESC && key <= GLFW_KEY_MENU) {
        mapped_key = Glfw_high_key_map[key - GLFW_KEY_ESC];
    }

    if (mapped_key != Input_key::INVALID) {
        size_t ordinal = input_key_ordinal(mapped_key);
        Input_key_down[ordinal] = (action != GLFW_RELEASE);
        Input_key_hit[ordinal] |= (action == GLFW_PRESS);
    }
}

static void char_callback(int unicode_point, int action) {
    if (action == GLFW_PRESS && Input_pending_unicode_length < MAX_PENDING_UNICODE) {
        Input_pending_unicode[Input_pending_unicode_length++] = static_cast<wchar_t>(unicode_point);
    }
}

static void mouse_button_callback(int button, int action) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        Input_pointer_info[0].down = (action != GLFW_RELEASE);
        Input_pointer_info[0].clicked |= (action == GLFW_PRESS);
    }
}


bool input_init_web() {
    bool res = true;

    Input_num_pointers = 1;

    glfwSetMouseButtonCallback(mouse_button_callback);
    glfwSetKeyCallback(key_callback);
    glfwSetCharCallback(char_callback);

    return res;
}

void input_poll_web() {
    // poll os events and deliver them
    glfwPollEvents();
    
    int x, y;
    glfwGetMousePos(&x, &y);
    Input_pointer_info[0].x = (float)x;
    Input_pointer_info[0].y = (float)y;
}

void input_shutdown_web() {

}
