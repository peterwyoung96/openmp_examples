#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <omp.h>

struct Particle 
{
    float x, y;
    float vx, vy;
};

int main() 
{
    const int N = 1000;
    const float dt = 0.01f;

    std::vector<Particle> particles(N);

    // Initialize particles
    for (int i = 0; i < N; i++) {
        particles[i] = {
            static_cast<float>(i % 100),
            static_cast<float>(i / 100),
            1.0f,
            1.0f
        };
    }

    double total_energy = 0.0;

    // Thread-local energy accumulation (avoids contention)
    #pragma omp parallel
    {
        double local_energy = 0.0;
        std::ostringstream log_buffer;

        #pragma omp for
        for (int i = 0; i < N; i++) {

            // --- physics update (independent work) ---
            particles[i].vx += -0.1f * particles[i].x * dt;
            particles[i].vy += -0.1f * particles[i].y * dt;

            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;

            // --- compute energy ---
            double e = 0.5 * (particles[i].vx * particles[i].vx +
                              particles[i].vy * particles[i].vy);

            local_energy += e;

            // --- occasional logging (safe, but buffered) ---
            if (i % 250 == 0) {
                log_buffer << "Thread " << omp_get_thread_num()
                           << " processed particle " << i
                           << " energy=" << e << "\n";
            }
        }

        // Merge local energy safely
        #pragma omp atomic
        total_energy += local_energy;

        // Print logs safely (only once per thread)
        #pragma omp critical
        {
            std::cout << log_buffer.str();
        }
    }

    std::cout << "Total energy = " << total_energy << "\n";

    return 0;
}