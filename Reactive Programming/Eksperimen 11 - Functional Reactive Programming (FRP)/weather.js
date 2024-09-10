const { fromEvent, interval } = require('rxjs');
const { map, filter, switchMap } = require('rxjs/operators');

// Fungsi simulasi yang menghasilkan data cuaca acak
function getWeatherData() {
    const weatherConditions = ['Sunny', 'Rainy', 'Cloudy', 'Stormy'];
    const temperature = Math.floor(Math.random() * 40); // Random temperature between 0 and 40
    const condition = weatherConditions[Math.floor(Math.random() * weatherConditions.length)];
    
    return {
        temperature: temperature,
        condition: condition
    };
}

// Simulasikan aliran data cuaca setiap 2 detik
const weatherStream = interval(2000).pipe(
    map(() => getWeatherData())
);

// Pemrosesan data cuaca menggunakan operator fungsional
const processedWeatherStream = weatherStream.pipe(
    // Filter hanya cuaca dengan suhu lebih dari 20 derajat Celsius
    filter(weather => weather.temperature > 20),

    // Mengubah suhu dari Celsius ke Fahrenheit
    map(weather => ({
        ...weather,
        temperature: (weather.temperature * 9/5) + 32
    }))
);

// Berlangganan ke aliran data yang sudah diproses dan menampilkan hasilnya
const subscription = processedWeatherStream.subscribe(weather => {
    console.log(`Temperature: ${weather.temperature}°F, Condition: ${weather.condition}`);
});

// Stop the subscription after 20 seconds
setTimeout(() => {
    subscription.unsubscribe();
    console.log('Stopped receiving weather updates.');
}, 20000);
