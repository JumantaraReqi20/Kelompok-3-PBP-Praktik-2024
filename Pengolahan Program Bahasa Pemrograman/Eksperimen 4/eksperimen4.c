#include <stdio.h>

int main() {
    // Inisialisasi array dan variabel untuk menghitung jumlah
    int numbers[] = {1, 2, 3, 4, 5};
    int sum = 0;
    int length = sizeof(numbers) / sizeof(numbers[0]);

    // Loop untuk menghitung jumlah elemen
    for (int i = 0; i < length; i++) {
        sum += numbers[i];
    }

    // Mencetak hasil
    printf("Jumlah elemen dalam array adalah: %d\n", sum);

    return 0;
}
