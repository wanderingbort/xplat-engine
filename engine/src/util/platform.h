#if !defined(__PLATFORM_H__)
#define __PLATFORM_H__

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


#endif //!defined(__PLATFORM_H__)