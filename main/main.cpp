#include <iostream>
#include <vector>
#include "../comb/combinatorics.h"


int main() {
    constexpr int N = 20;
    long long result = CompileTimeFactorial64<N>::value;
    std::cout << N << "! = " << result << std::endl;

    iter_choices([](std::vector<int> v) {
        int length = v.size();
        std::cout << length << std::endl;
    });

    return 0;
}
