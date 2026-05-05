#include <iostream>
#include <omp.h>

int main() 
{
    double start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < 100000000; i++) {
        // dummy work
    }

    double end = omp_get_wtime();

    std::cout << "Time: " << (end - start) << " seconds\n";
}