#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void check_raw_materials();
void run_production_line();
void quality_control();

double get_time() {
    return (double)clock() / CLOCKS_PER_SEC;
}

void profile_function(const char* name, void (*func)()) {
    double start = get_time();
    func();
    double end = get_time();
    printf("%s: %.3f detik\n", name, end - start);
}

void simulate_process(const char* process, int duration) {
    printf("Menjalankan %s...\n", process);
    sleep(duration);
}

void check_raw_materials() {
    simulate_process("Pemeriksaan Bahan Baku", 1);
}

void run_production_line() {
    simulate_process("Lini Produksi", 2);
}

void quality_control() {
    simulate_process("Kontrol Kualitas", 1);
}

void run_production_cycle() {
    check_raw_materials();
    run_production_line();
    quality_control();
}

int main() {
    printf("Sistem Pemantauan Produksi\n\n");

    printf("Menjalankan siklus produksi:\n");
    run_production_cycle();

    printf("\nAnalisis kinerja:\n");
    profile_function("Pemeriksaan Bahan Baku", check_raw_materials);
    profile_function("Lini Produksi", run_production_line);
    profile_function("Kontrol Kualitas", quality_control);

    return 0;
}