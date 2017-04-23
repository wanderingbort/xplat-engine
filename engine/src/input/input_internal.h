#if !defined(__INPUT_INTERNAL_H__)
#define __INPUT_INTERNAL_H__

#include "input_limits.h"

extern bool Input_key_down[NUM_INPUT_KEYS];
extern bool Input_key_hit[NUM_INPUT_KEYS];

extern wchar_t Input_pending_unicode[MAX_PENDING_UNICODE];
extern size_t Input_pending_unicode_length;

extern size_t Input_num_pointers;
extern Input_pointer_state Input_pointer_info[MAX_INPUT_POINTERS];

#endif