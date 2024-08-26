#include <stdio.h>

const int enableLogging = 1; // Set to 0 to disable logging

void log(const char *msg) {
    if (enableLogging) {
        printf("LOG: %s\n", msg);
    }
}

void perform_task() {
    log("Task started.");
    // Simulasi tugas
    printf("Performing task...\n");
    log("Task completed.");
}

int main() {
    perform_task();
    return 0;
}

//Untuk Cek ukuran file =  dir EksperimenTanpaMacro.exe
//Untuk Cek Kecepatan proses = Measure-Command { .\EksperimenTanpaMacro.exe }