// Scheduler.js
import { of, asyncScheduler } from 'rxjs';
import { observeOn, delay } from 'rxjs/operators';

// Fungsi untuk menjadwalkan eksekusi
export function scheduleTask(task$) {
    return task$.pipe(
        observeOn(asyncScheduler), // Menggunakan Scheduler untuk mengelola eksekusi
        delay(0) // Mengatur penundaan untuk simulasi jadwal
    );
}
