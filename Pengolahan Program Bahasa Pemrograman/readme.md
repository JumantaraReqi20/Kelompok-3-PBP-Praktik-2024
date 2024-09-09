# 📝 LAPORAN PRAKTIKUM  
## PRINSIP BAHASA PEMROGRAMAN  
### "Pengolahan Program Bahasa Pemrograman"  

📚 **Oleh: Kelompok 3**  
💻 **Kelas: 2A – D4 TEKNIK INFORMATIKA**  

🏫 **JURUSAN TEKNIK KOMPUTER DAN INFORMATIKA**  
📍 **POLITEKNIK NEGERI BANDUNG**  
🗓️ **2024**

---

## 🔬 Experiment 1: Memahami #include dan #import  

### 📌 Identifikasi Masalah  
- `#include`: Digunakan untuk menyertakan file header dalam C/C++. Bisa menyebabkan duplikasi deklarasi jika file header yang sama disertakan beberapa kali kecuali jika menggunakan guard.
- `#import`: Tidak ada di C/C++, tetapi penggunaan guard pada `#include` dapat memberikan efek yang sama seperti `#import` dalam mencegah duplikasi.

### 📄 Deskripsi Masalah  
- `#include` dengan guard: Mencegah penyertaan ganda dari file header.
- `#include` tanpa guard: Akan menyebabkan error jika file header yang sama disertakan beberapa kali.

### 🔧 Metodologi Eksperimen  
1. **Siapkan Lingkungan Pengembangan**  
   Pastikan memiliki lingkungan pengembangan yang mendukung C++ seperti Visual Studio Code (VSCode) atau IDE lain serta compiler seperti GCC atau Clang.

2. **Buat Dua File Header**  
   - **File Header Tanpa Perlindungan (`header1.h`)**  
     ```cpp
     // header1.h
     void functionFromHeader1();
     ```
   - **File Header dengan Perlindungan (`header2.h`)**  
     ```cpp
     // header2.h
     #ifndef HEADER2_H
     #define HEADER2_H
     void functionFromHeader2();
     #endif
     ```

3. **Buat File Utama**  
   Buat file sumber utama `main.cpp` yang menyertakan kedua file header (`header1.h` dan `header2.h`) lebih dari sekali.  
   ```cpp
   #include <iostream>
   #include "header1.h"
   #include "header1.h"  // Disertakan dua kali
   #include "header2.h"
   #include "header2.h"  // Disertakan dua kali dengan perlindungan

   void functionFromHeader1() {
       std::cout << "Function from header1.h" << std::endl;
   }

   void functionFromHeader2() {
       std::cout << "Function from header2.h" << std::endl;
   }

   int main() {
       functionFromHeader1();
       functionFromHeader2();
       return 0;
   }
4. **Pelaksanaan Eksperimen**
   [Link Eksperimen](https://chatgpt.com/share/ce80c80d-7e59-42a7-878c-637d4e2f4cc2)

## 🔬 Experiment 2: Perbandingan Static Library dan Dynamic Library  

### 📌 Identifikasi Masalah  
Perbedaan utama antara static library dan dynamic library adalah cara mereka terintegrasi dengan aplikasi dan kapan mereka dimuat ke dalam memori. Pertanyaan utamanya adalah bagaimana integrasi ini memengaruhi penggunaan memori dan waktu eksekusi aplikasi.

### 📄 Deskripsi Masalah  
- **Static Libraries** (.a di Linux atau .lib di Windows): Disatukan dengan program utama selama fase linking, menghasilkan file eksekusi yang lebih besar karena semua kode library digabungkan ke dalam executable.
- **Dynamic Libraries** (.so di Linux atau .dll di Windows): Di-load ke memori saat runtime, yang berarti executable lebih kecil, namun ada sedikit overhead saat loading library tersebut.

### 🔧 Metodologi Eksperimen  
1. **Implementasi Program**  
   Buat sebuah program sederhana yang melakukan operasi berulang, misalnya, perhitungan matematis atau manipulasi string, yang akan menggunakan fungsi dari library.

2. **Buat Dua Versi Library**  
   - **Static Library**: Kode library dikompilasi menjadi .a (Linux) atau .lib (Windows).
   - **Dynamic Library**: Kode library dikompilasi menjadi .so (Linux) atau .dll (Windows).

3. **Pengukuran**  
   - **Ukuran File Eksekusi**: Bandingkan ukuran file executable antara versi yang menggunakan static library dan dynamic library.
   - **Waktu Eksekusi**: Ukur waktu eksekusi program dalam kedua versi untuk melihat apakah ada perbedaan signifikan.
   - **Penggunaan Memori**: Pantau penggunaan memori saat runtime untuk melihat dampak penggunaan dynamic library.

### 🔗 Pelaksanaan Eksperimen  
[Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/02293c7e-bd26-4bfc-ae79-d9d926d9ef77)

### 📊 Analisis Hasil Eksperimen  
[Lihat Analisis Hasil Eksperimen](https://chatgpt.com/share/c608dcfe-c283-467c-80e2-0ede7e739c5a)

## 🔬 Experiment 3: Masalah Kompleks Terkait Header File dan `#define`

### 📌 Identifikasi Masalah  
Masalah kompleks terkait header file dan `#define`:
1. **Ketergantungan Antar File**: Sulit mengelola perubahan yang mempengaruhi banyak file.
2. **Kompleksitas Kode**: Makro sulit di-debug dan bisa menambah kompleksitas.
3. **Konflik Definisi**: Nama `#define` yang sama di berbagai file dapat menyebabkan konflik.
4. **Pemeliharaan**: Sulit memperbarui kode seiring pertumbuhan proyek.
5. **Optimasi Performa**: Penggunaan makro yang buruk dapat menurunkan performa.

### 📄 Deskripsi Masalah  
Header file digunakan untuk mendeklarasikan fungsi dan variabel global, sedangkan `#define` digunakan untuk konstanta dan macro. Apa dampaknya terhadap pemeliharaan kode?

### 🔧 Metodologi Eksperimen  
1. **Buat Program**  
   Buat program yang menggunakan header file dan `#define`.
   
2. **Implementasikan Beberapa Fungsi dan Variabel**  
   Implementasikan beberapa fungsi dan variabel yang berbeda.

### 🔗 Pelaksanaan Eksperimen  
1. **Siapkan Lingkungan Pengembangan**  
   Pastikan Anda memiliki lingkungan pengembangan yang mendukung bahasa C++, seperti Visual Studio Code (VSCode) atau IDE lain, serta compiler seperti GCC atau Clang.

2. **Buat Satu Header File dan Dua File `.c`**  
   - **Header File (`config.h`)**  
     ```cpp
     // config.h
     #ifndef CONFIG_H
     #define CONFIG_H

     #define PI 3.14159
     #define AREA_CIRCLE(radius) (PI * (radius) * (radius))

     int square(int x);
     int add(int a, int b);

     #endif
     ```

   - **File `.c` (functions.c)**  
     ```cpp
     // functions.c
     #include "config.h"

     int square(int x) {
         return x * x;
     }

     int add(int a, int b) {
         return a + b;
     }
     ```

   - **File `.c` (main.c)**  
     ```cpp
     // main.c
     #include <stdio.h>
     #include "config.h"

     int main() {
         int num = 5;
         int radius = 3;

         printf("Square of %d: %d\n", num, square(num));
         printf("Sum of %d and %d: %d\n", num, radius, add(num, radius));
         printf("Area of circle with radius %d: %.2f\n", radius, AREA_CIRCLE(radius));

         return 0;
     }
     ```

   [Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/6b67ffef-f8ac-4901-9495-2814127426f3)

## 🔬 Experiment 4: Keuntungan Menggunakan IDE dengan Fitur Debugging

### 📌 Identifikasi Masalah  
Apa keuntungan menggunakan IDE dengan fitur debugging dibandingkan dengan editor teks sederhana?  
Menggunakan IDE dengan fitur debugging memberikan keuntungan signifikan dibandingkan dengan editor teks sederhana. IDE menawarkan kemudahan dalam proses debugging melalui breakpoint dan langkah eksekusi, mempercepat pengembangan kode dengan auto-completion dan refactoring, serta mengintegrasikan alat pengembangan seperti sistem kontrol versi dan build tools. Selain itu, IDE menyediakan alat profiling dan analisis kinerja untuk mengoptimalkan aplikasi, serta meningkatkan produktivitas dengan fitur navigasi kode dan template. Secara keseluruhan, IDE mempermudah pengelolaan kode dan mempercepat proses pengembangan serta pemecahan masalah.

### 📄 Deskripsi Masalah  
IDE modern sering memiliki alat debugging yang kuat. Bagaimana ini mempengaruhi proses pengembangan dan pemecahan masalah?

Alat debugging yang kuat dalam IDE modern berdampak besar pada proses pengembangan dan pemecahan masalah sebagai berikut:

1. **Mempercepat Identifikasi Masalah**:
   - **Breakpoint dan Watchpoints**: Memungkinkan pengembang untuk menghentikan eksekusi kode pada titik tertentu dan memeriksa status aplikasi secara real-time, yang mempercepat identifikasi dan perbaikan bug.

2. **Mempermudah Analisis Kode**:
   - **Step-by-Step Execution**: Fitur ini membantu pengembang untuk menjalankan kode langkah demi langkah, memahami alur eksekusi, dan mengidentifikasi bagian kode yang menyebabkan masalah.
   - **Variable Inspection**: Memungkinkan pengembang untuk melihat dan memodifikasi nilai variabel selama eksekusi, membantu dalam memahami bagaimana data berubah.

3. **Meningkatkan Produktivitas**:
   - **Integrated Debugging**: Dengan alat debugging yang terintegrasi, pengembang tidak perlu beralih antara berbagai alat atau manual untuk memeriksa dan memperbaiki kode, sehingga proses pemecahan masalah menjadi lebih efisien.
   - **Automated Testing**: IDE sering terintegrasi dengan alat pengujian otomatis yang memudahkan pengujian kode secara berkala dan mendeteksi regresi.

4. **Meningkatkan Kualitas Kode**:
   - **Code Coverage**: Alat debugging sering menyediakan metrik cakupan kode untuk memastikan bahwa semua bagian kode diuji, membantu dalam meningkatkan kualitas kode.
   - **Profiling**: Profiling alat dalam IDE membantu menganalisis penggunaan sumber daya dan kinerja aplikasi, memungkinkan pengembang untuk mengoptimalkan kode dan mengurangi masalah kinerja.

5. **Memudahkan Kolaborasi Tim**:
   - **Shared Debugging Sessions**: Beberapa IDE memungkinkan sesi debugging bersama, memudahkan kolaborasi dalam tim untuk menyelesaikan masalah bersama dan berbagi wawasan.

Secara keseluruhan, alat debugging yang kuat dalam IDE modern menyederhanakan proses pengembangan dengan mempermudah identifikasi dan pemecahan masalah, meningkatkan efisiensi, dan membantu dalam menghasilkan kode berkualitas tinggi.

### 🔧 Metodologi Eksperimen  
1. **Pilih Dua Lingkungan Pengembangan**  
   Pilih satu lingkungan dengan IDE yang mendukung debugging dan satu tanpa.

2. **Kembangkan dan Debug Program**  
   Kembangkan dan debug program yang sama di kedua lingkungan.

### 🔗 Pelaksanaan Eksperimen  
[Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/86392f0d-6d03-4e7c-be5a-01dfcfd6cf32)

## 🔬 Experiment 5: Perbedaan Antara Proses Kompilasi dan Linking

### 📌 Identifikasi Masalah  
Apa perbedaan antara proses kompilasi dan linking dalam pengolahan program?  
- **Kompilasi**: Proses ini mengubah kode sumber (source code) yang ditulis dalam bahasa pemrograman tingkat tinggi (seperti C atau C++) menjadi kode objek (object code) dalam format biner. Compiler memeriksa sintaksis dan semantik kode sumber dan mengonversinya menjadi representasi mesin yang dapat dipahami oleh komputer.
- **Linking**: Setelah kompilasi, kode objek perlu digabungkan menjadi file executable yang dapat dijalankan. Linking menggabungkan beberapa file objek dan library yang diperlukan, serta mengatur alamat memori untuk variabel dan fungsi yang digunakan dalam program.

### 📄 Deskripsi Masalah  
Kompilasi mengubah kode sumber menjadi objek, sedangkan linking menggabungkan objek menjadi executable. Bagaimana ini mempengaruhi waktu dan output akhir?
- **Waktu Kompilasi**: Waktu yang dibutuhkan untuk mengubah kode sumber menjadi file objek. Waktu ini dipengaruhi oleh kompleksitas dan ukuran kode sumber serta efisiensi compiler.
- **Waktu Linking**: Waktu yang dibutuhkan untuk menggabungkan file objek dan library menjadi file executable. Linking biasanya lebih cepat daripada kompilasi karena hanya menggabungkan file objek yang sudah dikompilasi.
- **Output Akhir**: Output akhir dari kompilasi adalah file objek, sedangkan output akhir dari linking adalah file executable yang siap dijalankan pada sistem operasi.

### 🔧 Metodologi Eksperimen  
1. **Buat Program dengan Beberapa File Sumber**:
   - **main.c**:
     ```c
     #include <stdio.h>
     #include "utils.h"
     #include "math_ops.h"
     
     int main() {
         printf("Sum: %d\n", add(5, 10));
         return 0;
     }
     ```
   
   - **utils.c**:
     ```c
     #include "utils.h"
     
     void print_hello() {
         printf("Hello, World!\n");
     }
     ```
   
   - **utils.h**:
     ```c
     #ifndef UTILS_H
     #define UTILS_H
     
     void print_hello();
     
     #endif
     ```
   
   - **math_ops.c**:
     ```c
     #include "math_ops.h"
     
     int add(int a, int b) {
         return a + b;
     }
     ```
   
   - **math_ops.h**:
     ```c
     #ifndef MATH_OPS_H
     #define MATH_OPS_H
     
     int add(int a, int b);
     
     #endif
     ```

2. **Kompilasi dan Link Program Tersebut**:
   - **Kompilasi main.c**  
     Waktu eksekusi: 229.0701 ms
   
   - **Kompilasi utils.c**  
     Waktu eksekusi: 225.7392 ms
   
   - **Kompilasi math_ops.c**  
     Waktu eksekusi: 194.6725 ms
   
   - **Linking**  
     Menggabungkan file `.o` dari hasil compile sebelumnya  
     Waktu eksekusi: 230.8467 ms

### 🔗 Pelaksanaan Eksperimen  
[Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/bf7d60f7-bb7a-470d-bf95-98b1e4f5c6d8)

## 🔬 Experiment 6: Penggunaan #pragma dan #assert dalam Pengembangan dan Debugging

### 📌 Identifikasi Masalah  
**Pertanyaan**: Bagaimana penggunaan `#pragma` dan `#assert` mempengaruhi pengembangan dan debugging?  
**Latar Belakang**:
- **`#pragma`** adalah direktif preprosesor yang memberikan instruksi khusus kepada kompilator, yang dapat mempengaruhi cara kode dikompilasi dan dioptimalkan.
- **`#assert`** adalah makro yang digunakan untuk memvalidasi kondisi pada runtime, membantu dalam mendeteksi bug dengan memastikan bahwa kondisi tertentu benar selama eksekusi program.

### 📄 Deskripsi Masalah  
Penggunaan `#pragma` dan `#assert` dapat meningkatkan proses debugging dengan mengontrol optimasi kompilator dan memvalidasi kondisi selama runtime. Ini membantu mendeteksi dan memperbaiki kesalahan lebih cepat, serta mencegah masalah yang mungkin sulit diidentifikasi tanpa alat ini.

### 🔧 Metodologi Eksperimen  
**Penggunaan `#pragma`**:
- Mengatur pengoptimalan dengan menggunakan direktif `#pragma` untuk melihat bagaimana perubahan pengaturan mempengaruhi hasil kompilasi dan performa program.

**Penggunaan `#assert`**:
- Memeriksa kondisi runtime dengan menggunakan `#assert` untuk memastikan bahwa program berfungsi seperti yang diharapkan dan untuk menangkap kesalahan logika.

**a. Implementasi Kode**

- **Versi Tanpa `#pragma` dan `#assert`**:
  ```c
  #include <stdio.h>
  
  int main() {
      int x = 10;
      int y = 0;
      
      // Bagian kode yang mungkin menyebabkan masalah
      int result = x / y;
      printf("Result: %d\n", result);
      return 0;
  }
  ```
- **Versi Dengan `#pragma` dan `#assert`**:
  ```c
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
  ```
### 🔗 Pelaksanaan Eksperimen  
[Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/747932ba-a223-41a3-bd39-312dc1e82fff)

## 🧪 Experiment 7: Reflection dalam Bahasa Pemrograman

### 📌 Identifikasi Masalah
Bagaimana reflection digunakan untuk introspeksi objek dan memodifikasi struktur program pada runtime?

### 📄 Deskripsi Masalah
Reflection adalah fitur dalam beberapa bahasa pemrograman, seperti Java dan Python, yang memungkinkan inspeksi dan modifikasi program saat runtime. Ini memungkinkan program untuk melihat atau memodifikasi struktur dirinya sendiri, seperti kelas, metode, dan variabel. 

**Manfaat utama reflection:**
- **Fleksibilitas:** Memungkinkan program untuk beradaptasi dengan berbagai skenario pada runtime.

**Risiko penggunaan reflection:**
- **Peningkatan kompleksitas kode:** Dapat membuat kode lebih sulit dibaca dan dipelihara.
- **Potensi bug yang sulit dilacak:** Kesalahan yang timbul dari reflection sering kali sulit didiagnosis.
- **Penurunan performa:** Operasi reflection dapat memperlambat kinerja aplikasi.

### 🔧 Metodologi Eksperimen
1. **Langkah 1:** Implementasikan fitur reflection dalam sebuah program sederhana.
2. **Langkah 2:** Lakukan introspeksi objek, seperti mengambil nama kelas, daftar metode, dan variabel yang ada pada kelas tersebut.
3. **Langkah 3:** Modifikasi objek tersebut, misalnya, dengan mengubah nilai variabel atau menambahkan metode baru saat runtime.

### 🔗 Pelaksanaan Eksperimen
[Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/8efeeb7e-2118-4681-9ebf-852806255cf5)

### 📊 Analisis Hasil Eksperimen
**Manfaat:** Dengan reflection, kita dapat melakukan introspeksi objek dan memodifikasi struktur program pada runtime, yang memberikan fleksibilitas lebih dalam situasi di mana kode perlu beradaptasi dengan perubahan lingkungan atau data yang tidak diketahui sebelumnya.

## 🧪 Experiment 8: Instrumentasi Kode untuk Profiling

### 📌 Identifikasi Masalah
Bagaimana instrumentasi kode mempengaruhi performa aplikasi dan proses profiling?

### 📄 Deskripsi Masalah
Instrumentasi kode adalah teknik menambahkan kode tambahan ke dalam program untuk mengumpulkan informasi performa, seperti waktu eksekusi, penggunaan memori, atau jejak pemanggilan fungsi. Namun, penambahan kode ini dapat mempengaruhi kinerja asli dari aplikasi. Eksperimen ini bertujuan untuk mengukur dampak dari instrumentasi kode terhadap performa aplikasi dan hasil profiling.

### 🔧 Metodologi Eksperimen
1. **Langkah 1:** Pilih aplikasi Java sederhana yang akan diuji, misalnya program yang menghitung faktorial dari suatu bilangan.
2. **Langkah 2:** Ukur performa aplikasi sebelum menambahkan instrumentasi, seperti waktu eksekusi dan penggunaan memori.
3. **Langkah 3:** Tambahkan kode instrumentasi untuk mengukur waktu eksekusi setiap fungsi dan penggunaan memori secara real-time.
4. **Langkah 4:** Ukur kembali performa aplikasi setelah penambahan instrumentasi.
5. **Langkah 5:** Bandingkan hasil dari sebelum dan sesudah instrumentasi untuk mengevaluasi dampaknya terhadap performa.

### 🔗 Pelaksanaan Eksperimen
[Lihat Pelaksanaan Eksperimen](https://chatgpt.com/share/34ab25db-7072-4863-bd9b-f8f0d9378ea6)

### 📊 Analisis Hasil Eksperimen
**Performa:** Bandingkan waktu eksekusi antara program asli dan program yang diinstrumentasi. Program yang diinstrumentasi biasanya akan memiliki waktu eksekusi yang lebih lama karena overhead dari kode instrumentasi.

**Profiling Data:** Tinjau data profiling untuk melihat bagaimana fungsi dan metode dalam aplikasi digunakan dan berapa lama mereka berjalan. Analisis ini dapat memberikan wawasan tentang bagian-bagian kode yang paling mempengaruhi performa.

## 🧪 Experiment 9: Macro dalam Pemrograman

### 📌 Identifikasi Problem
Bagaimana penggunaan macro mempengaruhi pemrograman dan efisiensi kode?

### 📄 Deskripsi Problem
Macro adalah potongan kode yang digantikan sebelum kompilasi. Kode ini sering digunakan untuk meningkatkan efisiensi dan konsistensi, terutama dalam hal logging, pengaturan konfigurasi, dan pengoptimalan performa. Namun, perlu dievaluasi bagaimana macro mempengaruhi pemeliharaan kode dan kinerja program.

### 🔧 Metodologi Eksperimen
1. **Buat Macro**:
   - Buat beberapa macro sederhana untuk tujuan logging dalam program.
   - Contoh macro akan membedakan antara kode yang menggunakan logging dengan yang tidak.
2. **Bandingkan Kode**:
   - Gunakan macro untuk mengaktifkan atau menonaktifkan logging.
   - Bandingkan kode yang menggunakan macro dengan kode yang menulis logging secara manual atau tidak menggunakan logging sama sekali.

### 🔗 Pelaksanaan Eksperimen
[Link Eksperimen 9](https://chatgpt.com/c/492b5d58-8b2d-4fc2-80bd-788083d93ec7)

1. **Implementasi Macro**:
   - Buat sebuah program sederhana dengan macro untuk logging.
   - Jalankan program dengan `LOGGING_ENABLED` diaktifkan dan dinonaktifkan.
2. **Periksa Performa**:
   - Gunakan tools seperti `Measure-Command` di PowerShell untuk mengukur waktu eksekusi program.
   - Gunakan perintah `dir` untuk memeriksa ukuran file executable.

### 📊 Analisis Hasil Eksperimen
1. **Efisiensi Kode**:
   - Saat `LOGGING_ENABLED` diaktifkan, program mencatat pesan log, dan ukuran file serta waktu eksekusi mungkin sedikit lebih besar karena adanya tambahan proses logging.
   - Saat `LOGGING_ENABLED` dinonaktifkan, macro menghilangkan kode logging dari program, menghasilkan file yang lebih kecil dan potensi waktu eksekusi yang lebih cepat.
2. **Pemeliharaan Kode**:
   - Menggunakan macro untuk logging mempermudah pengelolaan kode, terutama jika Anda perlu mengaktifkan atau menonaktifkan logging di seluruh aplikasi.
   - Namun, terlalu banyak macro dapat membuat kode sulit dibaca dan dipahami.
3. **Hasil Akhir**:
   - Kode dengan macro menawarkan fleksibilitas dan efisiensi, terutama dalam pengembangan dan debugging. Macro memungkinkan developer untuk dengan cepat mengaktifkan atau menonaktifkan fitur seperti logging tanpa harus mengubah kode di banyak tempat.
  
## 🧪 Experiment 10: Call Graph dan Profiling

### 📌 Identifikasi Problem
Call graph dan profiling digunakan untuk menganalisis dan mengoptimalkan performa program dengan cara memetakan alur pemanggilan fungsi dan mengukur waktu eksekusi masing-masing fungsi dalam sistem pemantauan produksi.

### 📄 Deskripsi Problem
Dalam kode yang diberikan, call graph direpresentasikan oleh fungsi `run_production_cycle()` yang menunjukkan urutan pemanggilan fungsi-fungsi produksi. Profiling diimplementasikan menggunakan fungsi `profile_function()` yang mengukur waktu eksekusi setiap fungsi. Kedua teknik ini berkontribusi pada optimasi dengan mengidentifikasi alur program dan mengungkap fungsi-fungsi yang memakan waktu paling lama.

### 🔧 Metodologi Eksperimen
1. **Program**: Dibuat dengan tiga fungsi utama: `check_raw_materials()`, `run_production_line()`, dan `quality_control()`.
2. **Call Graph**: Diimplementasikan dalam `run_production_cycle()`.
3. **Profiling**: Dilakukan menggunakan `profile_function()` untuk setiap fungsi utama.
4. **Jalankan Program**: Program dijalankan untuk mendapatkan hasil call graph dan profiling.

### 🔗 Pelaksanaan Eksperimen
[Link Eksperimen 10](https://claude.ai/chat/a8dd17e7-9df6-44dc-b280-a41ea9ec0932)
1. **Call Graph**: Diimplementasikan dalam fungsi `run_production_cycle()`, yang memanggil ketiga fungsi utama secara berurutan.
2. **Profiling**: Diimplementasikan menggunakan `profile_function()`, yang mengukur waktu eksekusi setiap fungsi.
3. **Eksekusi Program**: Program dijalankan, menampilkan urutan eksekusi (call graph) dan waktu eksekusi (profiling) untuk setiap fungsi.

### 📊 Analisis Hasil Eksperimen
1. **Call Graph**: Menunjukkan urutan eksekusi: `check_raw_materials` -> `run_production_line` -> `quality_control`.
2. **Profiling**: Mengungkap bahwa `run_production_line` memakan waktu paling lama (2 detik), sementara `check_raw_materials` dan `quality_control` masing-masing memakan waktu 1 detik.
3. **Identifikasi Bottleneck**: Bottleneck performa teridentifikasi pada `run_production_line`, yang menjadi target utama untuk optimasi.
4. **Optimasi**: Dapat difokuskan pada peningkatan efisiensi lini produksi, karena fungsi ini memakan waktu dua kali lipat dibandingkan fungsi-fungsi lainnya.

## 🧪 Experiment 11: Directive #define dan #ifdef

### 📌 Identifikasi Masalah
Bagaimana penggunaan `#define` dan `#ifdef` dalam pengembangan perangkat lunak skala besar mempengaruhi manajemen konfigurasi, pengujian, dan distribusi berbagai versi produk?

### 📄 Deskripsi Masalah
Dalam industri perangkat lunak, pengelolaan berbagai konfigurasi dan versi produk adalah tugas yang kompleks dan penting. `#define` dan `#ifdef` sering digunakan untuk menciptakan variasi dari kode yang sama untuk mendukung berbagai platform, fitur, atau konfigurasi pelanggan. Tantangan muncul dalam memastikan bahwa kode tetap dapat di-maintain, diuji dengan benar, dan didistribusikan tanpa bug atau masalah kompatibilitas.

Eksperimen ini akan mengeksplorasi bagaimana `#define` dan `#ifdef` dapat digunakan secara efisien dalam pengembangan perangkat lunak skala besar, terutama ketika tim pengembangan perlu mengelola berbagai konfigurasi produk dan memastikan kualitasnya.

### 🔧 Metodologi Eksperimen
1. **Buat beberapa konfigurasi kode** yang mensimulasikan pengembangan produk untuk berbagai platform atau fitur pelanggan menggunakan `#define` dan `#ifdef`.
2. **Kompilasi dan jalankan program** dengan berbagai konfigurasi untuk melihat bagaimana perbedaan ini memengaruhi hasil akhir.
3. **Analisis dampak** terhadap fleksibilitas, kompleksitas, serta pengujian dan distribusi kode.

### 🔗 Pelaksanaan Eksperimen
[Link Eksperimen 11](#)

### 📊 Analisis Hasil Eksperimen
Dengan menggunakan `#define` dan `#ifdef`, perusahaan dapat mengelola berbagai konfigurasi produk dengan lebih efisien. Namun, semakin banyak kondisi kompilasi yang ditambahkan, semakin kompleks kode dan pengujiannya. Hal ini menuntut keterampilan khusus untuk mengelola dan menguji berbagai konfigurasi, yang langka dan sangat dicari di industri.

## 🧪 Experiment 12: Penggunaan Annotation dalam Metaprogramming untuk Otomatisasi Kode di Industri Perangkat Lunak

### 📌 Identifikasi Masalah
Bagaimana annotation dapat digunakan dalam metaprogramming untuk mengotomatiskan pembuatan dan modifikasi kode di lingkungan pengembangan perangkat lunak yang kompleks, terutama dalam konteks skalabilitas dan efisiensi pengembangan? Ini menjadi penting di industri karena mengurangi kode boilerplate, mempercepat pengembangan, dan membuat kode lebih fleksibel dan mudah dikelola. Namun, kemampuan untuk menguasai teknik ini langka dan sangat dicari.

### 📄 Deskripsi Masalah
Dalam pengembangan perangkat lunak, terutama pada proyek-proyek besar yang memerlukan skala dan modularitas tinggi, banyak kode yang dihasilkan adalah kode boilerplate yang berulang. Penggunaan annotation bersama dengan metaprogramming dapat mengotomatisasi proses ini, tetapi penerapannya tidak sederhana dan memerlukan pemahaman mendalam tentang bagaimana compiler atau runtime memproses metadata.

Eksperimen ini akan mengeksplorasi bagaimana annotation dapat digunakan untuk mengotomatisasi pembuatan kode di lingkungan industri, yang dapat menghasilkan penghematan waktu dan meningkatkan kualitas kode, tetapi juga memerlukan keahlian khusus yang jarang dimiliki.

### 🔧 Metodologi Eksperimen
1. **Identifikasi area dalam kode industri** di mana boilerplate code umum terjadi (misalnya, pembuatan getter/setter, pengaturan keamanan, atau validasi).
2. **Implementasikan annotation** yang dirancang untuk mengotomatiskan pembuatan bagian kode ini.
3. **Gunakan metaprogramming** untuk memproses annotation dan menghasilkan atau memodifikasi kode secara dinamis.
4. **Uji implementasi ini** di lingkungan yang mirip dengan produksi untuk menilai pengaruhnya terhadap efisiensi dan skalabilitas.

### 🔗 Pelaksanaan Eksperimen
[Link Eksperimen 12](#)

### 📊 Analisis Hasil Eksperimen
- **Manfaat**: Otomatisasi kode melalui annotation dapat secara signifikan mengurangi waktu pengembangan, mengurangi kesalahan manusia, dan meningkatkan konsistensi kode, yang sangat relevan di industri dengan kebutuhan skalabilitas tinggi.
- **Kompleksitas**: Penggunaan teknik ini memerlukan keahlian khusus yang jarang dimiliki, menjadikannya langka tetapi sangat berharga. Kesalahan dalam penerapan dapat menyebabkan bug yang sulit diidentifikasi, sehingga memerlukan pengujian yang ketat.



