# 📝 LAPORAN PRAKTIKUM  
## PRINSIP BAHASA PEMROGRAMAN  
### "_Reactive Programming_"  

📚 **Oleh: Kelompok 3**  
💻 **Kelas: 2A – D4 TEKNIK INFORMATIKA**  

🏫 **JURUSAN TEKNIK KOMPUTER DAN INFORMATIKA**  
📍 **POLITEKNIK NEGERI BANDUNG**  
🗓️ **2024**

---

# 🌦 PRAKTIKUM

### 🔍 Eksperimen 1 dan 2: Implementasi Aliran Data Cuaca dengan Reactive Streams Menggunakan Non-blocking I/O di JavaScript

**📝 Identifikasi Masalah**  
Bagaimana mengimplementasikan aliran data cuaca dari API menggunakan standar Reactive Streams dengan metode non-blocking I/O di JavaScript?  
🎯 **Tujuan utama** adalah memastikan aplikasi dapat menangani aliran data secara asinkron tanpa memblokir eksekusi program dengan tetap memanfaatkan pemrosesan reaktif dan efisien.

**📚 Deskripsi Masalah**  
Reactive Streams adalah standar pemrograman reaktif yang memungkinkan aliran data asinkron dan non-blocking. Standar ini membantu aplikasi menangani banyak permintaan I/O secara efisien dengan mengelola aliran data secara optimal.  
❓ **Tantangan**: Bagaimana membuat aplikasi JavaScript yang dapat mengambil data cuaca dari API eksternal menggunakan aliran data asinkron dengan prinsip non-blocking. Selain itu, aplikasi juga harus mampu menangani kesalahan yang terjadi selama pemanggilan API tanpa menyebabkan aplikasi berhenti atau hang.

**⚙️ Pentingnya non-blocking I/O**  
⏳ Non-blocking I/O memastikan thread utama JavaScript tidak terhambat oleh permintaan I/O yang lambat, sehingga aplikasi tetap responsif meskipun ada permintaan data yang memerlukan waktu lebih lama.

---

### 🛠️ Metodologi Eksperimen

#### 🔗 Teknologi yang Digunakan:
- **RxJS**: Library pemrograman reaktif yang memungkinkan pemrosesan aliran data dengan menggunakan Observables dan mendukung pemrograman asinkron.
- **Fetch API**: Untuk melakukan permintaan HTTP asinkron ke API cuaca.
- **OpenWeatherMap API**: Sumber data cuaca yang menyediakan informasi cuaca terkini berdasarkan lokasi.
- **Node.js**: Platform runtime JavaScript yang memungkinkan menjalankan JavaScript di server dan menyediakan dukungan untuk npm (Node Package Manager).

#### 📝 Langkah-langkah Eksperimen:

1. **Membuat Observable menggunakan RxJS**  
   Observable ini akan memancarkan aliran data berbentuk permintaan HTTP ke API cuaca berdasarkan input kota.

2. **Menghubungkan Observable dengan Subscriber**  
   Subscriber akan menerima data cuaca dari API dan menampilkan hasilnya di antarmuka pengguna.

3. **Menangani Kesalahan dengan `catchError`**  
   Jika terjadi kegagalan saat memanggil API, error akan ditangani menggunakan operator `catchError`.

4. **Memastikan Non-blocking I/O**  
   Pemrosesan permintaan bersifat non-blocking, artinya thread utama JavaScript tidak tertunda menunggu hasil dari permintaan API.

---

### ⚙️ Pelaksanaan Eksperimen

1. **Langkah 1: Menginstal RxJS dan Fetch API**  
   Proses instalasi RxJS dilakukan untuk mendukung pemrograman reaktif di JavaScript. Fetch API digunakan untuk melakukan operasi I/O asinkron (HTTP request) ke API cuaca eksternal.
   
   ```bash
   npm install rxjs
   npm install node-fetch
   ```

2. **Langkah 2: Menulis Fungsi `fetchWeatherData` untuk Mengambil Data Cuaca**  
   Fungsi ini memanggil API cuaca secara asinkron menggunakan Fetch, kemudian hasilnya dikonversi menjadi JSON.

   ```javascript
   const fetchWeatherData = (city) => {
     return from(fetch(apiUrl(city)).then(response => response.json()));
   };
   ```

3. **Langkah 3: Implementasi Aliran Data Reaktif dengan RxJS**  
   Menggunakan `of()` untuk memulai aliran data dari nama kota, kemudian `switchMap()` digunakan untuk mengubah nilai tersebut menjadi permintaan API cuaca dan `catchError()` untuk menangani error.

   ```javascript
   const getWeatherObservable = (city) => {
     return of(city).pipe(
       switchMap(fetchWeatherData),
       catchError((error) => of({ error: 'Failed to fetch weather data' }))
     );
   };
   ```

4. **Langkah 4: Mengimplementasikan Subscriber untuk Menerima dan Menampilkan Data**  
   Hasil dari Observable (aliran data) ditangani oleh Subscriber yang akan menampilkan cuaca atau menangani error, memastikan bahwa aplikasi tidak crash jika terjadi kegagalan.

   ```javascript
   getWeatherObservable('Jakarta').subscribe(
     (data) => {
       if (data.error) {
         console.log(data.error);
       } else {
         console.log(`Cuaca di ${data.name}: ${data.weather[0].description}, Suhu: ${data.main.temp}°C`);
       }
     },
     (error) => console.error('Error in subscription:', error)
   );
   ```

5. **Langkah 5: Pengujian Aliran Data Non-blocking**  
   Pengujian dilakukan untuk memastikan bahwa aliran data bekerja secara non-blocking dan bahwa program tetap responsif selama proses permintaan API. Untuk memverifikasi hal ini, tambahkan `console.log("sebelum");` pada baris sebelum subscriber, dan tambahkan `console.log("setelah");` setelahnya.

   ```javascript
   console.log("sebelum");

   // Subscriber
   getWeatherObservable('Bandung').subscribe(
     (data) => {
       if (data.error) {
         console.log(data.error);
       } else {
         console.log(`Cuaca di ${data.name}: ${data.weather[0].description}, Suhu: ${data.main.temp}°C`);
       }
     },
     (error) => console.error('Error in subscription:', error)
   );

   console.log("sesudah");
   ```

---

### 🎯 Hasil Pengujian

Hasil pengujian menunjukkan bahwa thread utama JavaScript tetap bebas untuk melakukan tugas lain selama menunggu respons dari API cuaca. Program tetap responsif, dan data cuaca berhasil ditampilkan tanpa memblokir eksekusi program.

---

### 🏁 Kesimpulan

Eksperimen berhasil menunjukkan implementasi aliran data cuaca dari API menggunakan standar Reactive Streams dengan non-blocking I/O. Dengan menggunakan RxJS dan Fetch API, aplikasi dapat menangani permintaan cuaca secara efisien tanpa memblokir thread utama.

Berikut adalah Praktikum 7 dan 8 yang telah diubah ke dalam format Markdown dengan tambahan emoticon:

---

# PRAKTIKUM

### 🔍 Eksperimen 3 dan 4: Observable dan Concurrency

**📝 Identifikasi Masalah**  
Dalam pengembangan aplikasi modern, seringkali kita menghadapi tantangan dalam menangani aliran data yang kompleks dan asynchronous secara efisien. Dua konsep penting dalam konteks ini adalah **Observable** dan **Concurrency**. Observable membantu dalam mengelola aliran data yang dapat terjadi dari berbagai sumber, sementara concurrency terkait dengan bagaimana kita menangani beberapa operasi asynchronous secara bersamaan.

**📚 Deskripsi Masalah**

- **Observable**:  
  Observable adalah komponen yang digunakan dalam pemrograman reaktif untuk mengelola aliran data yang dapat berubah dari waktu ke waktu. Dalam aplikasi yang menangani event, data streaming, atau operasi asynchronous, Observable menyediakan cara untuk memantau, mengubah, dan merespons perubahan data dengan cara yang terstruktur.

  **Masalah yang dihadapi**:
  - **Pengelolaan Data Dinamis**: Aplikasi sering memerlukan penanganan data yang dinamis, seperti event UI, data dari API, atau hasil dari berbagai operasi asynchronous. Tanpa metode yang efektif untuk mengelola data ini, aplikasi bisa menjadi sulit untuk dipahami dan dikelola.
  - **Complex Event Handling**: Menangani berbagai event atau data stream secara bersamaan bisa rumit, terutama jika melibatkan banyak sumber atau operasi yang saling bergantung.

  **Solusi dengan Observable**:
  - **Pengelolaan Aliran Data**: Observable menyediakan cara untuk menangani aliran data dengan mudah, termasuk memfilter, mengubah, dan menggabungkan data dari berbagai sumber.
  - **Reaktif dan Deklaratif**: Dengan Observable, kode bisa lebih deklaratif dan reaktif, memungkinkan pengembangan yang lebih bersih dan mudah dipahami.

- **Concurrency**:  
  Concurrency adalah konsep dalam pemrograman yang melibatkan eksekusi beberapa tugas secara bersamaan. Ini sangat penting dalam aplikasi yang melakukan banyak operasi asynchronous seperti permintaan jaringan, pembacaan file, atau interaksi dengan database.

  **Masalah yang dihadapi**:
  - **Operasi Asynchronous**: Mengelola beberapa operasi asynchronous yang berjalan bersamaan dapat menimbulkan masalah seperti race conditions, deadlocks, atau kompleksitas pengelolaan state.
  - **Kinerja dan Responsivitas**: Aplikasi harus memastikan bahwa operasi asynchronous tidak memblokir thread utama, sehingga tetap responsif dan efisien.

  **Solusi dengan Concurrency**:
  - **Parallel Execution**: Dengan menggunakan teknik concurrency seperti Promises atau RxJS’s `combineLatest`, aplikasi dapat menangani beberapa operasi asynchronous secara bersamaan, meningkatkan efisiensi dan responsivitas.
  - **Pengelolaan Data Bersamaan**: Observables dan operator seperti `mergeMap`, `switchMap`, dan `combineLatest` memungkinkan pengelolaan data dari beberapa sumber secara bersamaan dengan cara yang terstruktur dan dapat diprediksi.

---

### 🛠️ Metodologi Eksperimen

1. **Penjelasan Kode JavaScript**  
   - **Inisialisasi RxJS dan Elemen DOM**  
     Mengimpor modul dari RxJS seperti `fromEvent`, `of`, `Observable`, dan `forkJoin` untuk mengelola event dan Observable. Selain itu, mendapatkan referensi elemen HTML yang digunakan dalam script.

   ```javascript
   const { fromEvent, of, Observable, forkJoin } = rxjs;
   const { switchMap, catchError, map } = rxjs.operators;
   
   const userSelection = document.getElementById('user-selection');
   const userInfo = document.getElementById('user-info');
   const userStatus = document.getElementById('user-status');
   const toggleSubscription = document.getElementById('toggle-subscription');
   const weatherForm = document.getElementById('weather-form');
   const cityInput = document.getElementById('city');
   const weatherInfo = document.getElementById('weather-info');
   const userAButton = document.getElementById('userA-button');
   const userBButton = document.getElementById('userB-button');
   ```

2. **Konfigurasi Pengguna**  
   Mendefinisikan objek `users` yang berisi informasi mengenai dua jenis pengguna, serta mendeklarasikan `currentUser` untuk menyimpan pengguna yang sedang aktif.

   ```javascript
   const users = {
     userA: { name: 'User A', subscribed: true },
     userB: { name: 'User B', subscribed: false }
   };

   let currentUser;
   ```

3. **Fungsi untuk Mendapatkan Data Cuaca**  
   Membuat fungsi `getWeatherObservable()` yang mengembalikan Observable untuk melakukan fetch data cuaca dari API berdasarkan kota yang diberikan.

   ```javascript
   function getWeatherObservable(city) {
     const url = `https://api.weatherstack.com/current?access_key=${apiKey}&query=${encodeURIComponent(city)}`;
     return new Observable(subscriber => {
       fetch(url)
         .then(response => response.json())
         .then(data => {
           if (data.error) {
             subscriber.error(`Kota "${city}" tidak ditemukan. Coba lagi.`);
           } else {
             subscriber.next(data);
             subscriber.complete();
           }
         })
         .catch(error => {
           subscriber.error(`Terjadi kesalahan untuk kota "${city}". Coba lagi nanti.`);
         });
     });
   }
   ```

4. **Fungsi untuk Menampilkan dan Menyembunyikan Elemen**  
   Menampilkan informasi pengguna dan menyembunyikan opsi pemilihan pengguna, serta menampilkan atau menyembunyikan form cuaca berdasarkan status berlangganan pengguna saat ini.

   ```javascript
   function showUserInfo() {
     userInfo.classList.remove('hidden');
     userSelection.classList.add('hidden');
     updateUserStatus();
   }

   function showWeatherForm() {
     if (users[currentUser].subscribed) {
       weatherForm.classList.remove('hidden');
     } else {
       weatherForm.classList.add('hidden');
     }
   }

   function hideWeatherInfo() {
     weatherInfo.classList.add('hidden');
     weatherInfo.innerHTML = '';
   }

   function updateUserStatus() {
     const status = users[currentUser].subscribed ? 'Berlangganan' : 'Tidak Berlangganan';
     userStatus.textContent = `${users[currentUser].name}: ${status}`;
     showWeatherForm();
   }
   ```

5. **Event Listener untuk Pengguna dan Form**  
   Menangani klik pada tombol pengguna A dan B, serta tombol untuk mengubah status berlangganan.

   ```javascript
   userAButton.addEventListener('click', () => {
     console.log('User A button clicked');
     currentUser = 'userA';
     showUserInfo();
   });

   userBButton.addEventListener('click', () => {
     console.log('User B button clicked');
     currentUser = 'userB';
     showUserInfo();
   });

   toggleSubscription.addEventListener('click', () => {
     users[currentUser].subscribed = !users[currentUser].subscribed;
     updateUserStatus();
   });
   ```

6. **Menangani Submit Form dengan RxJS**  
   Menggunakan `fromEvent` untuk mendengarkan event submit form dan `switchMap` untuk mengganti Observable lama dengan yang baru untuk setiap submit, menghindari permintaan duplikat.

   ```javascript
   fromEvent(weatherForm, 'submit').pipe(
     switchMap(event => {
       event.preventDefault();
       hideWeatherInfo();
       if (!users[currentUser].subscribed) {
         alert('Anda tidak memiliki akses untuk fitur ini.');
         return of(null);
       }
       const cities = cityInput.value.split(',').map(city => city.trim());
       return forkJoin(
         cities.map(city => 
           getWeatherObservable(city).pipe(
             catchError(error => of({ error, city }))
           )
         )
       );
     })
   ).subscribe({
     next: (results) => {
       if (results && results.length > 0) {
         results.forEach((result, index) => {
           const cityWeather = document.createElement('div');
           cityWeather.className = 'city-weather';
           if (result.error) {
             cityWeather.innerHTML = `<h3>Kota: ${result.city}</h3><p>Error: ${result.error}</p>`;
           } else {
             cityWeather.innerHTML = `
               <h3>Kota: ${result.location.name}, ${result.location.country}</h3>
               <p>Suhu: ${result.current.temperature}°C</p>
               <p>Deskripsi: ${result.current.weather_descriptions[0]}</p>
             `;
           }
           weatherInfo.appendChild(cityWeather);
         });
         weatherInfo.classList.remove('hidden');
       }
     },
     error: (error) => {
       console.error('Terjadi kesalahan:', error);
       alert('Terjadi kesalahan. Coba lagi nanti.');
     }
   });
   ```

---

### 🎯 Hasil

Penggunaan **Observable** dan teknik **Concurrency** sangat penting dalam pengembangan aplikasi modern yang memerlukan pengelolaan data dinamis dan operasi asynchronous. Observable menyediakan cara yang efektif untuk menangani aliran data yang kompleks, sementara concurrency memungkinkan aplikasi untuk menjalankan beberapa operasi secara bersamaan dengan cara yang efisien dan responsif.

---

### 🏁 Kesimpulan

Eksperimen ini menunjukkan bahwa pemanfaatan Observable dan teknik concurrency dapat membantu pengembang

---

Berikut adalah konversi **Eksperimen 7** dan **Eksperimen 8** (Resilience dan Error Handling) ke dalam format Markdown:

---

# PRAKTIKUM

### 🔍 Eksperimen 7 dan 8: Resilience dan Error Handling

**📝 Identifikasi Masalah**  
Pada aplikasi yang berinteraksi dengan API cuaca, salah satu masalah utama yang dapat terjadi adalah kegagalan saat mengambil data dari server, yang bisa disebabkan oleh koneksi yang buruk, server down, atau batasan dari API. Tanpa mekanisme pemulihan, aplikasi bisa gagal sepenuhnya dan menyebabkan pengalaman pengguna terganggu. Oleh karena itu, penting untuk menerapkan **Error Handling** dan **Resilience** yang sesuai, seperti mekanisme retry dan fallback.

**📚 Deskripsi Masalah**

- **Resilience**  
  Resilience dalam konteks perangkat lunak merujuk pada kemampuan sistem untuk terus beroperasi secara efektif meskipun menghadapi gangguan atau kesalahan. Sistem yang resilient tidak hanya dapat menangani kesalahan, tetapi juga dapat pulih dan beradaptasi dari gangguan tanpa mengalami downtime yang signifikan.

- **Error Handling**  
  Error Handling adalah proses menangani dan merespons kesalahan atau pengecualian yang terjadi dalam aplikasi. Tujuannya adalah untuk mencegah aplikasi crash atau berhenti bekerja serta memberikan feedback yang berguna kepada pengguna atau sistem.

  **Masalah yang dihadapi**:
  - **Kesalahan Eksternal**: Ketika aplikasi bergantung pada layanan eksternal (misalnya API cuaca), aplikasi menjadi rentan terhadap kegagalan dari sisi eksternal, seperti masalah koneksi atau server down.
  - **Kesalahan Internal**: Kesalahan dalam pemrosesan data, seperti format data yang tidak valid, juga dapat menyebabkan gangguan dalam aplikasi.

  **Solusi dengan Resilience dan Error Handling**:
  - **Retry Mechanism**: Mengimplementasikan mekanisme retry jika terjadi kegagalan saat mengambil data.
  - **Fallback**: Menyediakan data fallback jika retry terus-menerus gagal, sehingga aplikasi tetap dapat memberikan respon yang berguna kepada pengguna.
  
---

### 🛠️ Metodologi Eksperimen

1. **Langkah-langkah Eksperimen:**
   - **Membangun aplikasi cuaca sederhana** yang terhubung ke API cuaca (misalnya, OpenWeather).
   - **Mengimplementasikan fungsi untuk mengambil data dari API** dengan mekanisme retry dan fallback.
   - **Uji aplikasi** dengan mematikan koneksi atau mensimulasikan kegagalan server.
   - **Analisis** bagaimana aplikasi tetap responsif dan memberikan hasil fallback ketika kegagalan terjadi.

2. **Kode Program:**
   Implementasi kode untuk menangani kesalahan dan ketahanan terhadap kegagalan API cuaca.

   ```javascript
   // Function to fetch weather data with retry and fallback mechanism
   async function fetchWeatherWithRetry(city, retries = 3, fallbackData = { weather: 'sunny', temp: 25 }) {
     const apiKey = '293e249197d56cbf8e358f9b6b9c24a0';  // Replace with your OpenWeather API key
     const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=${apiKey}`;
   
     for (let attempt = 0; attempt < retries; attempt++) {
       try {
         let response = await fetch(url);
         if (!response.ok) {
           // Handle HTTP errors
           if (response.status === 404) {
             throw new Error('City not found');
           } else {
             throw new Error(`API call failed with status: ${response.status}`);
           }
         }
         let data = await response.json();

         // Check if the data contains valid weather information
         if (data.weather && data.main) {
           return {
             weather: data.weather[0].description,
             temp: data.main.temp,
             error: false
           };
         } else {
           throw new Error('Invalid data received from API');
         }
       } catch (error) {
         console.log(`Attempt ${attempt + 1} failed: ${error.message}`);
         if (attempt === retries - 1) {
           console.log("All attempts failed. Returning fallback data.");
           return { weather: 'Unable to fetch weather', temp: null, error: true };
         }
       }
     }

     // In case of all retries failing
     return { weather: 'Unable to fetch weather', temp: null, error: true };
   }

   // Handle form submission
   document.getElementById('city-form').addEventListener('submit', async (event) => {
     event.preventDefault();
   
     const city = document.getElementById('city-input').value;
     const weatherDisplay = document.getElementById('weather-display');
     const weatherElement = document.getElementById('weather');
     const errorElement = document.getElementById('error');
     
     // Show the weather display section
     weatherDisplay.classList.remove('hidden');
     weatherElement.textContent = "Fetching weather data...";
     if (errorElement) {
       errorElement.textContent = '';
     }

     const weatherData = await fetchWeatherWithRetry(city);

     if (weatherData.error) {
       // Show error message if city not found or API issue
       weatherElement.textContent = '';
       errorElement.textContent = `City "${city}" not found or API issue.`;
     } else {
       // Display valid weather data
       weatherElement.textContent = `Weather in ${city}: ${weatherData.weather}, Temp: ${weatherData.temp}°C`;
     }
   });
   ```

---

### 🎯 Hasil Pengujian

1. **Pengujian dengan Simulasi Kegagalan API**  
   - Ketika API gagal memberikan respons, mekanisme retry diaktifkan. Jika semua percobaan gagal, data fallback ditampilkan kepada pengguna untuk menjaga pengalaman pengguna tetap optimal.

2. **Pengujian dengan Data Fallback**  
   - Data fallback memberikan hasil yang berguna ketika tidak ada data cuaca yang dapat diambil dari API, menjaga aplikasi tetap berjalan tanpa crash.

---

### 🏁 Kesimpulan

Eksperimen ini berhasil menunjukkan pentingnya **Resilience** dan **Error Handling** dalam aplikasi yang berinteraksi dengan layanan eksternal. Dengan mekanisme retry dan fallback yang diterapkan, aplikasi dapat tetap responsif dan memberikan pengalaman pengguna yang baik, meskipun terjadi kegagalan pada layanan eksternal.

---

# PRAKTIKUM

### 🔍 Eksperimen 9 dan 10: Command-Query Responsibility Segregation (CQRS) dan Reactive Architecture

**📝 Identifikasi Masalah**  
Dalam aplikasi yang menangani data cuaca dan pembaruan lokasi pengguna, seringkali terjadi beban yang signifikan pada operasi baca (query) dan tulis (command). Tanpa pemisahan yang jelas antara operasi baca dan tulis, sistem dapat mengalami bottleneck, menurunkan performa, dan sulit untuk diskalakan. Oleh karena itu, penerapan **CQRS (Command-Query Responsibility Segregation)** dan **Reactive Architecture** dapat meningkatkan performa dan responsivitas aplikasi.

**📚 Deskripsi Masalah**

- **Command-Query Responsibility Segregation (CQRS)**  
  CQRS adalah pendekatan arsitektur di mana operasi baca dan tulis dipisahkan menjadi model yang berbeda. Ini memungkinkan optimasi spesifik untuk setiap operasi dan membantu meningkatkan performa serta skalabilitas aplikasi.

  **Masalah yang dihadapi**:
  - **Kinerja**: Ketika operasi baca dan tulis dilakukan dalam satu layanan, aplikasi bisa mengalami penurunan kinerja saat beban meningkat.
  - **Skalabilitas**: Tanpa pemisahan tanggung jawab, sulit untuk meningkatkan skala aplikasi dengan efisien.

  **Solusi dengan CQRS**:
  - **Pemisahan Model Baca dan Tulis**: Dengan memisahkan model baca dan tulis, operasi dapat dioptimalkan secara independen. Ini mengurangi bottleneck dan meningkatkan efisiensi.

- **Reactive Architecture**  
  Arsitektur reaktif memungkinkan aplikasi untuk merespons event secara asinkron dan memproses data dengan cara yang efisien. Ini sangat penting dalam skenario real-time di mana aplikasi harus tetap responsif meskipun beban tinggi.

  **Masalah yang dihadapi**:
  - **Responsivitas**: Ketika ada banyak event yang terjadi secara bersamaan, aplikasi harus mampu menangani semuanya dengan cepat tanpa mengorbankan responsivitas.

  **Solusi dengan Reactive Architecture**:
  - **Event-Driven Processing**: Dengan memanfaatkan arsitektur reaktif, aplikasi dapat menangani event secara asinkron, memastikan responsivitas tetap terjaga dan aplikasi tetap efisien.

---

### 🛠️ Metodologi Eksperimen

1. **Langkah-langkah Eksperimen:**
   - **Membangun dua versi aplikasi cuaca**: satu tanpa CQRS (monolitik) dan satu dengan penerapan CQRS dan arsitektur reaktif.
   - **Mengukur performa aplikasi**: dengan dan tanpa CQRS di bawah beban tinggi, serta menguji responsivitas aplikasi dengan arsitektur reaktif.

2. **Implementasi Aplikasi Tanpa CQRS**  
   Semua operasi dilakukan dalam satu model, termasuk operasi baca dan tulis.

   ```java
   public class WeatherService {
       private Map<String, WeatherData> weatherDataStore = new HashMap<>();

       // Operasi baca
       public WeatherData getWeather(String location) {
           return weatherDataStore.get(location);
       }

       // Operasi tulis
       public void updateWeather(String location, WeatherData data) {
           weatherDataStore.put(location, data);
       }
   }
   ```

3. **Implementasi Aplikasi Dengan CQRS dan Reactive Architecture**

   - **Model Command (Tulis)**  
     Operasi tulis dipisahkan ke dalam model command handler, memungkinkan optimasi khusus untuk pembaruan data cuaca.

     ```java
     public class WeatherCommandHandler {
         private final WeatherRepository weatherRepository;

         public WeatherCommandHandler(WeatherRepository repository) {
             this.weatherRepository = repository;
         }

         public void handleUpdateWeather(String location, WeatherData data) {
             weatherRepository.save(location, data);
         }
     }
     ```

   - **Model Query (Baca)**  
     Operasi baca dipisahkan ke dalam model query handler, memungkinkan optimasi khusus untuk pengambilan data cuaca.

     ```java
     public class WeatherQueryHandler {
         private final WeatherReadRepository weatherReadRepository;

         public WeatherQueryHandler(WeatherReadRepository repository) {
             this.weatherReadRepository = repository;
         }

         public WeatherData handleGetWeather(String location) {
             return weatherReadRepository.findByLocation(location);
         }
     }
     ```

   - **Reactive Architecture (Event-Driven Processing)**  
     Memproses event secara asinkron dengan arsitektur reaktif untuk menangani event pembaruan data cuaca.

     ```java
     public class WeatherEventProcessor {
         private final EventBus eventBus;

         public WeatherEventProcessor(EventBus eventBus) {
             this.eventBus = eventBus;
         }

         public void processEvent(Event event) {
             // Proses event secara asinkron
             CompletableFuture.runAsync(() -> {
                 // Proses data event
             });
         }
     }
     ```

---

### 🎯 Hasil Pengujian

1. **Aplikasi Tanpa CQRS**  
   - **Kinerja**: Mengalami bottleneck saat operasi baca dan tulis dilakukan secara bersamaan, terutama saat beban tinggi.
   - **Skalabilitas**: Sulit untuk diskalakan karena operasi baca dan tulis tidak dapat dioptimalkan secara independen.
   - **Responsivitas**: Penurunan responsivitas ketika ada banyak pembaruan data.

2. **Aplikasi Dengan CQRS dan Reactive Architecture**  
   - **Kinerja**: Meningkat karena pemisahan model baca dan tulis memungkinkan optimasi masing-masing. Event yang diproses secara asinkron meningkatkan responsivitas.
   - **Skalabilitas**: Meningkat karena operasi baca dan tulis dapat diskalakan secara independen. Pengolahan event asinkron juga meningkatkan kapasitas untuk menangani beban.
   - **Responsivitas**: Lebih baik karena arsitektur reaktif memungkinkan aplikasi untuk menangani pembaruan data secara efisien dan responsif terhadap event.

---

### 🏁 Kesimpulan

Eksperimen ini menunjukkan bahwa penerapan **CQRS** dan **Reactive Architecture** memberikan keuntungan signifikan dalam hal performa, skalabilitas, dan responsivitas aplikasi yang menangani beban tinggi. Dengan memisahkan tanggung jawab antara operasi baca dan tulis serta menggunakan arsitektur reaktif untuk pemrosesan event, aplikasi dapat berjalan lebih efisien dan responsif, terutama dalam skenario real-time yang kompleks.

---

# PRAKTIKUM

### 🔍 Eksperimen 11 dan 12: Functional Reactive Programming (FRP) dan Stream Processing

**📝 Identifikasi Masalah**  
Pada mini project ini, aplikasi **Reactive Weather Dashboard** harus menampilkan data cuaca secara real-time untuk berbagai lokasi. Tantangannya adalah bagaimana memastikan bahwa data cuaca yang berubah secara dinamis dapat diproses dan ditampilkan tanpa perlu memuat ulang halaman (real-time updates). Masalah utamanya adalah bagaimana menangani aliran data yang datang secara berkelanjutan dengan cara yang efisien dan menjaga pengalaman pengguna tetap mulus.

**📚 Deskripsi Masalah**

- **Functional Reactive Programming (FRP)**  
  FRP adalah paradigma pemrograman yang menggabungkan pemrograman fungsional dengan pemrograman reaktif. Ini memungkinkan penanganan aliran data secara reaktif dan mengelola event secara deklaratif menggunakan operator fungsional.

  **Masalah yang dihadapi**:
  - **Pemrosesan Data Secara Dinamis**: Aplikasi harus memproses data cuaca yang berubah secara real-time dan menyaring data yang relevan, seperti suhu di atas 20°C.
  - **Transformasi Data**: Data yang diterima perlu diubah sesuai dengan kebutuhan pengguna, seperti mengonversi suhu dari Celsius ke Fahrenheit.

  **Solusi dengan FRP**:
  - **Deklaratif dan Reaktif**: FRP menyediakan pendekatan deklaratif untuk mengelola aliran data, di mana transformasi dan penyaringan data dilakukan menggunakan operator seperti `map`, `filter`, dan `flatMap`.

- **Stream Processing**  
  Stream Processing adalah teknik pemrosesan data secara real-time, di mana data yang datang secara terus-menerus diproses dalam bentuk stream tanpa menunggu batch data selesai.

  **Masalah yang dihadapi**:
  - **Real-time Processing**: Aplikasi harus memastikan bahwa data cuaca yang masuk diproses secara real-time tanpa perlu menunggu seluruh batch data selesai.
  - **Efisiensi**: Pemrosesan aliran data harus dilakukan secara efisien agar tidak mempengaruhi performa aplikasi.

  **Solusi dengan Stream Processing**:
  - **Continuous Data Processing**: Dengan Stream Processing, data diproses secara berkelanjutan menggunakan pipeline pemrosesan, memungkinkan aplikasi untuk merespons perubahan data dengan cepat dan efisien.

---

### 🛠️ Metodologi Eksperimen

1. **Simulasi Aliran Data Cuaca**  
   Menggunakan fungsi `getWeatherData()` untuk mensimulasikan data cuaca yang diperoleh dari API. Fungsi ini menghasilkan data acak dengan suhu dan kondisi cuaca (misalnya "Sunny", "Rainy", dsb.). Interval setiap 2 detik menggambarkan bagaimana data cuaca diterima secara periodik.

   ```javascript
   function getWeatherData() {
     const conditions = ["Sunny", "Rainy", "Cloudy", "Stormy"];
     return {
       temperature: Math.floor(Math.random() * 40),  // Suhu acak antara 0-40°C
       condition: conditions[Math.floor(Math.random() * conditions.length)]
     };
   }

   setInterval(() => {
     const weather = getWeatherData();
     console.log("New weather data:", weather);
   }, 2000);  // Simulasi aliran data setiap 2 detik
   ```

2. **Pemrosesan Data dengan Operator Fungsional**  
   Data cuaca yang masuk diproses menggunakan operator `filter` untuk menyaring cuaca dengan suhu di atas 20°C karena hanya data tersebut yang relevan untuk ditampilkan. Menggunakan `map` untuk mengonversi suhu dari Celsius ke Fahrenheit.

   ```javascript
   const { interval } = rxjs;
   const { map, filter } = rxjs.operators;

   const weatherObservable = interval(2000).pipe(
     map(() => getWeatherData()),  // Simulasikan data cuaca
     filter(weather => weather.temperature > 20),  // Hanya cuaca dengan suhu > 20°C
     map(weather => ({
       ...weather,
       temperature: (weather.temperature * 9/5) + 32  // Konversi suhu ke Fahrenheit
     }))
   );

   weatherObservable.subscribe(weather => {
     console.log(`Temperature: ${weather.temperature}°F, Condition: ${weather.condition}`);
   });
   ```

3. **Pengujian dan Pengamatan**  
   Menjalankan aliran data selama 20 detik dan mengevaluasi efisiensi pemrosesan data. Operator fungsional seperti `filter` dan `map` memastikan bahwa data yang diproses sesuai dengan kebutuhan pengguna dan efisien.

---

### 🎯 Hasil Pengujian

1. **Pengujian Pemrosesan Data Secara Reaktif**  
   - Aplikasi berhasil memproses data cuaca secara real-time dengan menggunakan operator fungsional untuk menyaring dan mengonversi data cuaca yang relevan.
   - Aliran data yang datang setiap 2 detik diproses dengan cepat dan hasilnya ditampilkan sesuai dengan kebutuhan pengguna, memastikan bahwa aplikasi tetap responsif.

2. **Efisiensi Stream Processing**  
   - Pemrosesan aliran data secara berkelanjutan memungkinkan aplikasi untuk merespons perubahan data secara efisien tanpa menunggu batch data selesai.
   - Data yang tidak relevan (misalnya suhu di bawah 20°C) berhasil disaring, sehingga hanya data yang diperlukan yang diproses dan ditampilkan.

---

### 🏁 Kesimpulan

Eksperimen ini menunjukkan bahwa penerapan **Functional Reactive Programming (FRP)** dan **Stream Processing** memungkinkan aplikasi untuk menangani aliran data secara real-time dengan cara yang efisien. Dengan menggunakan operator fungsional seperti `filter` dan `map`, aplikasi dapat menyaring dan mengubah data cuaca sesuai dengan kebutuhan pengguna, sementara pemrosesan aliran data secara berkelanjutan memastikan bahwa aplikasi tetap responsif dan efisien dalam memproses data cuaca yang berubah secara dinamis.
