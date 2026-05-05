#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    const int N = 20;
    std::vector<int> arr(N);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        arr[i] = i * i; // each iter is independent
    }

    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}