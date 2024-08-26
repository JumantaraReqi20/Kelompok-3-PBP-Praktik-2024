#include <stdio.h>

// Simulasi konfigurasi produk untuk berbagai platform dan fitur
#define PLATFORM_WINDOWS
#define FEATURE_ADVANCED_SECURITY

int main() {
#ifdef PLATFORM_WINDOWS
    printf("Compiling for Windows platform.\n");
#elif defined(PLATFORM_LINUX)
    printf("Compiling for Linux platform.\n");
#else
    printf("Compiling for unknown platform.\n");
#endif

#ifdef FEATURE_ADVANCED_SECURITY
    printf("Advanced security features enabled.\n");
#else
    printf("Basic security features enabled.\n");
#endif

    return 0;
}

/*
Penjelasan Kode:
Jika didefinisikan PLATfORM_WINDOWS, program akan dikompilasi untuk platform Windows dengan menampilkan pesan "Compiling for Windows platform".
Jika didefinisikan FEATURE_ADVANCED_SECURITY, fitur keamanan lanjutan akan diaktifkan dalam produk.
*/
