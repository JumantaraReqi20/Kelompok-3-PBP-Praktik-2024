#include <stdio.h>
#include <time.h>

void log_message(const char* message) {
    // Ubah nilai flag di sini untuk mengaktifkan atau menonaktifkan logging
    const int LOGGING_ENABLED = 0;

    if (LOGGING_ENABLED) {
        printf("LOG: %s\n", message);
    }
}

int main() {
    log_message("Program dimulai.");

    clock_t start = clock();

    // Contoh operasi sederhana
    int result = 0;
    for (int i = 0; i < 1000000; i++) {
        result += i;
    }

    log_message("Loop selesai.");

    printf("Hasil akhir: %d\n", result);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    log_message("Program selesai.");
    printf("Waktu eksekusi: %f detik\n", time_spent);

    return 0;
}

/* Syntax untuk compiling:
 * g++ -o EksperimenTanpaMacro EksperimenTanpaMacro.cpp
 *
 * Syntax untuk menjalankan program:
 * ./EksperimenTanpaMacro
 *
 * Syntax untuk memeriksa ukuran file executable:
 * dir EksperimenTanpaMacro.exe (Windows)
 * ls -lh EksperimenTanpaMacro (Linux/MacOS)
 *
 * Syntax untuk memeriksa kecepatan eksekusi program (di PowerShell):
 * Measure-Command { ./EksperimenTanpaMacro }
 */
