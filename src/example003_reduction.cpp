#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    std::vector<int> data(1000, 1);
    int sum = 0;

    // Including "reduction" prevents race conditions.
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < data.size(); ++i) {
        sum += data[i];
    }

    std::cout << "sum = " << sum << "\n";

    return 0;
}