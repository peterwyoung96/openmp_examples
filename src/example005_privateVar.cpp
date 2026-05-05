#include <iostream>
#include <omp.h>

int main() 
{
    int x = 10;

    #pragma omp parallel private(x)
    {
        // Each thread gets its OWN copy of x
        x = omp_get_thread_num();

        #pragma omp critical
        {
            std::cout << "Thread " << omp_get_thread_num()
                    << " x = " << x << "\n";
        }
    }

    return 0;
}