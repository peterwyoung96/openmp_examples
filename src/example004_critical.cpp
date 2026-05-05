#include <iostream>
#include <omp.h>

int main()
{
    int counter = 0;

    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {

        // Only one thread at a time enters this block
        #pragma omp critical
        {
            int id = omp_get_thread_num();
            int n  = omp_get_num_threads();

            std::cout << "Entered via thread " << id
                << " of " << n << "\n";
            
            counter++;
        }
    }

    std::cout << "counter = " << counter << "\n";

    return 0;
}