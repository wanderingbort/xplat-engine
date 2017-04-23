#if !defined(__INPUT_LIMITS_H__)
#define __INPUT_LIMITS_H__

#include "input.h"
#include <type_traits>

inline size_t input_key_ordinal(Input_key key) {
    return static_cast<std::underlying_type<Input_key>::type>(key);
}

static size_t const NUM_INPUT_KEYS = static_cast<std::underlying_type<Input_key>::type>(Input_key::COUNT);
static size_t const MAX_PENDING_UNICODE = 1024;
static size_t const MAX_INPUT_POINTERS = 4;

#endif