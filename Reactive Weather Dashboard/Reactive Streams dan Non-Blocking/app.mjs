import {from, of} from 'rxjs';
import { switchMap, catchError } from 'rxjs/operators';
import fetch from 'node-fetch'; // Menggunakan fetch API untuk permintaan HTTP


// Ganti dengan API key OpenWeatherMap Anda
const apiKey = '293e249197d56cbf8e358f9b6b9c24a0';
const apiUrl = (city) => `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`;

// Fungsi untuk mendapatkan data cuaca dari API
const fetchWeatherData = (city) => {
  return from(fetch(apiUrl(city)).then(response => response.json()));
};

// Implementasi aliran data cuaca
const getWeatherObservable = (city) => {
  return of(city).pipe(
    switchMap(fetchWeatherData), // Memproses hasil dari API
    catchError((error) => {
      console.error('Error fetching weather data:', error);
      return of({ error: 'Failed to fetch weather data' }); // Tangani error
    })
  );
};

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
