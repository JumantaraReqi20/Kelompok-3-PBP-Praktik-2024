// main.c
#include <stdio.h>
#include "config.h"

int main() {
    int num = 5;
    int radius = 3;

    printf("Square of %d: %d\n", num, square(num));
    printf("Sum of %d and %d: %d\n", num, radius, add(num, radius));
    printf("Area of circle with radius %d: %.2f\n", radius, AREA_CIRCLE(radius));

    return 0;
}

