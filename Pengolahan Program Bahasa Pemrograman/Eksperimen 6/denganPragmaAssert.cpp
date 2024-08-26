#include <stdio.h>
#include <assert.h>

// #pragma untuk mengatur level optimasi
#pragma optimize("", off)  // Matikan optimasi untuk debug

int main() {
    int x = 10;
    int y = 0;
    
    // Assertion untuk memeriksa kondisi runtime
    assert(y != 0);  // Memastikan y tidak nol sebelum pembagian
    
    int result = x / y;
    
    printf("Result: %d\n", result);
    return 0;
}

