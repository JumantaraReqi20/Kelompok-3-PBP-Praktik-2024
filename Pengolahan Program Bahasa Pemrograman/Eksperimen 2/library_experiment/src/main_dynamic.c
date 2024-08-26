#include <stdio.h>
#include "mymath.h"

int main() {
    int sum = add(5, 3);
    int product = multiply(5, 3);
    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}
