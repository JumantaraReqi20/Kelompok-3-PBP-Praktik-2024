#include <stdio.h>

// Definisikan macro untuk logging
#define ENABLE_LOGGING

#ifdef ENABLE_LOGGING
    #define LOG(msg) printf("LOG: %s\n", msg)
#else
    #define LOG(msg) // Tidak ada output
#endif

void perform_task() {
    LOG("Task started.");
    // Simulasi tugas
    printf("Performing task...\n");
    LOG("Task completed.");
}

int main() {
    perform_task();
    return 0;
}

//Untuk Cek ukuran file =  dir EksperimenMacro.exe
//Untuk Cek Kecepatan proses = Measure-Command { .\EksperimenMacro.exe }