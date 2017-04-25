#if !defined(__PLATFORM_H__)
#define __PLATFORM_H__

#include <type_traits>

#if defined(__WEB__)
    #define PLATFORM web
    #define PLATFORM_HEADER web.h
#else
    #error("Unknown Platform");
#endif

#define MAKE_PLATFORM_NAME2(name, platform) name##_##platform
#define MAKE_PLATFORM_NAME(name, platform) MAKE_PLATFORM_NAME2(name, platform)
#define platform_call(fn, ...) MAKE_PLATFORM_NAME(fn, PLATFORM)(__VA_ARGS__)

#define MAKE_PLATFORM_INCLUDE3(name) #name
#define MAKE_PLATFORM_INCLUDE2(name, platform) MAKE_PLATFORM_INCLUDE3(name##_##platform)
#define MAKE_PLATFORM_INCLUDE(name, platform) MAKE_PLATFORM_INCLUDE2(name, platform)
#define platform_header(name) MAKE_PLATFORM_INCLUDE(name, PLATFORM_HEADER)


#define _DECLARE_HOOK(OPTIONAL, R_TYPE, R_KEYWORD, R_VALUE, METHOD_NAME, ...)\
template<typename ...ARGS>\
struct __hook_helper_##METHOD_NAME\
{\
    template<typename A>\
    static std::true_type test(R_TYPE (A::*)(ARGS...) ) {\
        return std::true_type();\
    }\
    template <typename A> \
    static decltype(test(&A::METHOD_NAME))\
    test(decltype(&A::METHOD_NAME),void *) {\
        typedef decltype(test(&A::METHOD_NAME)) return_type; \
        return return_type();\
    }\
    template<typename A>\
    static std::false_type test(...) {\
        return std::false_type(); \
    }\
    typedef decltype(test<PLATFORM_HOOKS>(0,0)) type;\
    static R_TYPE _eval(PLATFORM_HOOKS& t, ARGS... args, std::true_type) {\
        R_KEYWORD t.METHOD_NAME(args...);\
    }\
    static R_TYPE _eval(...){\
        R_KEYWORD R_VALUE;\
    }\
    static R_TYPE eval(PLATFORM_HOOKS& t, ARGS... args) {\
        static_assert(OPTIONAL || type(), "Non-optional method '" #METHOD_NAME "' is not implemented by platform");\
        R_KEYWORD _eval(t, args..., type());\
    }\
};\
template<typename ...ARGS>\
R_TYPE METHOD_NAME(ARGS... args) {\
    R_KEYWORD __hook_helper_##METHOD_NAME<__VA_ARGS__>::eval(platform_hooks, args...);\
}

#define DECLARE_OPTIONAL_HOOK(R_TYPE, R_VAL, METHOD_NAME, ...) _DECLARE_HOOK(true, R_TYPE, return, R_VAL, METHOD_NAME, __VA_ARGS__)
#define DECLARE_REQUIRED_HOOK(R_TYPE, METHOD_NAME, ...) _DECLARE_HOOK(false, R_TYPE, return, *(R_TYPE *)nullptr, METHOD_NAME, __VA_ARGS__)
#define DECLARE_OPTIONAL_HOOK_VOID(METHOD_NAME, ...) _DECLARE_HOOK(true, void, , , METHOD_NAME, __VA_ARGS__)
#define DECLARE_REQUIRED_HOOK_VOID(METHOD_NAME, ...) _DECLARE_HOOK(false, void, , ,METHOD_NAME, __VA_ARGS__)

#define HOOKS_CLASS(CLASS) CLASS##_hooks
#define DECLARE_HOOKS_START(CLASS) \
class CLASS;\
template<typename PLATFORM_HOOKS> \
class HOOKS_CLASS(CLASS) {\
public:\
    DECLARE_OPTIONAL_HOOK(bool, true, bind, CLASS *);

#define DECLARE_HOOKS_END()\
    PLATFORM_HOOKS platform_hooks;\
};

#define PLATFORM_CLASS(CLASS) MAKE_PLATFORM_NAME(CLASS, PLATFORM)
#define HOOKS(CLASS) HOOKS_CLASS(CLASS)<PLATFORM_CLASS(CLASS)>


#endif //!defined(__PLATFORM_H__)