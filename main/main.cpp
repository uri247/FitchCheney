#include <iostream>
#include <vector>
#include "../comb/combinatorics.h"


template<typename ty>
std::ostream& operator<<(std::ostream& os, const std::vector<ty>& vector) {
    using v_type = std::vector<int>;
    os << '[';
    for(auto p = vector.begin(); p != vector.end(); ++p) {
        os << *p;
        if( p + 1 != vector.end()) {
            os << ", ";
        }
    }
    os << ']';
}


int main() {
    constexpr int N = 20;
    long long result = CompileTimeFactorial64<N>::value;
    std::cout << N << "! = " << result << std::endl;

    iter_combinations(10, 3, [](const std::vector<int>& combination) {
        std::cout << combination << std::endl;
    });

    return 0;
}
