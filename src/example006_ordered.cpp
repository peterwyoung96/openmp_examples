#include <iostream>
#include <omp.h>

int main() 
{

    #pragma omp parallel for ordered
    for (int i = 0; i < 8; i++) {

        #pragma omp ordered
        {
            std::cout << "Iteration " << i << "\n";
        }
    }

    return 0;
}