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
