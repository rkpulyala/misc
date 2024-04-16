#include <cstdarg>
#include <cstdio>
#include <iostream>
/*
template <typename... Args>
constexpr char* allocate_format(const char* fmt_str, Args... args) {
    char* data = new char[100];
    std::snprintf(data, 100, fmt_str, args...);
    return data;
}

template <typename... Args>
[[nodiscard]] inline char* format(const char* fmt_str, Args... args) {
  return allocate_format(fmt_str, args...);
}
*/

char* format(const char* fmt_str, ...) {
    char* data = new char[100];
    va_list args;
    va_start(args, fmt_str);
    std::vsnprintf(data, 100, fmt_str, args);
    va_end(args);
    return data;
}

#define my_snprinf(dest_str, dest_len, fmt_str,...) std::snprintf(dest_str, dest_len, fmt_str, __VA_ARGS__)

#define my_snprinf2(fmt_str,...) ({ \
        char* dest_str = new char[100]; \
        std::snprintf(dest_str, 100, fmt_str, __VA_ARGS__); \
        dest_str; \
    })

int main() {
    char *str_int = format("Hello %d worlds\n", 100);
    char *str_fl = format("Hello %f worlds\n", 100.456);
    char *str_fl_fl = format("Hello %f worlds, %f people\n", 100.456, 1000000.345);
    printf("Hello %d worlds\n", 100);
    std::cout << str_int << std::endl;
    std::cout << str_fl << std::endl;
    std::cout << str_fl_fl << std::endl;

    /* GO BACK TO BASICS */
    char *str_int2 = new char[100];
    std::snprintf(str_int2, 100, "Hello %d worlds\n", 123);
    std::cout << str_int2 << std::endl;
    my_snprinf(str_int2, 100, "Hello %d worlds\n", 124);
    std::cout << str_int2 << std::endl;
    char *str_int3 = my_snprinf2("Hello %d worlds\n", 125);
    std::cout << str_int3 << std::endl;
    return 0;
}