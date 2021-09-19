#include <iostream>
#include <vector>
#include "combinatorics/combinatorics.h"






int main() {
    constexpr int N = 20;
    long long result = cb::CompileTimeFactorial64<N>::value;
    std::cout << N << "! = " << result << std::endl;

    /*
    cb::iter_combinations(10, 3, [](const std::vector<int>& combination) {
        std::cout << combination << std::endl;
    });
    */

    return 0;
}
