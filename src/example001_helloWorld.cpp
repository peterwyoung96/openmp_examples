#include <iostream>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int n  = omp_get_num_threads();

        std::cout << "Hello from thread " << id
                << " of " << n << "\n";
    }

    return 0;
}