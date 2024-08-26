#include <stdio.h>
#include <time.h>

// Macro untuk logging
#define LOGGING_ENABLED // Uncomment this line to enable logging

#ifdef LOGGING_ENABLED
    #define LOG(msg) printf("LOG: %s\n", msg)
#else
    #define LOG(msg)
#endif

int main() {
    LOG("Program dimulai.");

    clock_t start = clock();

    // Contoh operasi sederhana
    int result = 0;
    for (int i = 0; i < 1000000; i++) {
        result += i;
    }

    LOG("Loop selesai.");

    printf("Hasil akhir: %d\n", result);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    LOG("Program selesai.");
    printf("Waktu eksekusi: %f detik\n", time_spent);

    return 0;
}

/* Syntax untuk compiling:
 * g++ -o EksperimenMacro EksperimenMacro.cpp
 *
 * Syntax untuk menjalankan program:
 * ./EksperimenMacro
 *
 * Syntax untuk memeriksa ukuran file executable:
 * dir EksperimenMacro.exe (Windows)
 * ls -lh EksperimenMacro (Linux/MacOS)
 *
 * Syntax untuk memeriksa kecepatan eksekusi program (di PowerShell):
 * Measure-Command { ./EksperimenMacro }
 */
