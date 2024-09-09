import { from, interval } from 'rxjs';
import { switchMap, map, filter } from 'rxjs/operators';
import axios from 'axios'; // Pastikan axios juga diimpor dengan cara yang benar

// API Key dan URL untuk OpenWeatherMap
const apiKey = 'f22600d842e253a7379eb8fc6a82f5fd';
const apiUrl = (location) => `https://api.openweathermap.org/data/2.5/weather?q=${location}&appid=${apiKey}&units=metric`;

// Daftar lokasi yang ingin kita tampilkan cuacanya
const locations = ['Jakarta', 'Bandung', 'Surabaya', 'Denpasar'];

// Fungsi untuk mengambil data cuaca dari API
const fetchWeatherData = (location) => {
    return axios.get(apiUrl(location)).then(response => response.data);
};

// Membuat observable yang akan mengambil data cuaca setiap 10 detik
const weatherObservable = interval(10000).pipe(
    switchMap(() => from(locations)),  // Berpindah ke aliran data lokasi
    switchMap(location => fetchWeatherData(location)),  // Mengambil data cuaca untuk setiap lokasi
    filter(data => data.main.temp > 20),  // Hanya mengambil data jika suhu di atas 20°C
    map(data => ({  // Transformasi data menjadi format yang kita inginkan
        location: data.name,
        temperature: data.main.temp,
        description: data.weather[0].description
    }))
);

// Berlangganan ke observable untuk menampilkan data cuaca
weatherObservable.subscribe(
    (data) => {
        console.log(`Lokasi: ${data.location}, Suhu: ${data.temperature}°C, Kondisi: ${data.description}`);
    },
    (error) => {
        console.error('Error:', error);
    }
);
