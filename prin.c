#include <stdio.h>
#include "printf.h"

int main(void) {
    char *s = "world";
    int n = 123;
    double d = 3.14159;

    _printf("Hello, %s!\n", s);
    _printf("The number is: %d\n", n);
    _printf("The value of pi is: %f\n", d);

    return 0;
}
