#include <stdio.h>
#include <stdarg.h>

void test(const char *str, ...);

int main() {
    test("%c", 'q');
}

void test(const char *str, ...) {
    va_list vap;
    va_start(vap, str);
    putchar(va_arg(vap, int));
    va_end(vap);
}
