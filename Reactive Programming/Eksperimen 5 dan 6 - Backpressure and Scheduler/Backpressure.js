// Backpressure.js
import { from, of, asyncScheduler } from 'rxjs';
import { observeOn, throttleTime, switchMap } from 'rxjs/operators';

// Fungsi untuk menangani backpressure
export function handleBackpressure(data$) {
    return data$.pipe(
        observeOn(asyncScheduler), // Menggunakan Scheduler untuk mengelola eksekusi
        throttleTime(1000), // Mengatur frekuensi pemrosesan
        switchMap(data => of(data)) // Mengalihkan aliran data
    );
}
