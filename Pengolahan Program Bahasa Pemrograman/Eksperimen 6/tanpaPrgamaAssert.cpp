#include <stdio.h>

int main() {
    int x = 10;
    int y = 0;
    
    // Bagian kode yang mungkin menyebabkan masalah
    int result = x / y;
    
    printf("Result: %d\n", result);
    return 0;
}

