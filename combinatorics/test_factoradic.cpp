#include "combinatorics.h"

#include <cstdint>
#include <vector>


void simple_round_trip()
{
    std::vector<int> p{ 2, 3, 0, 4, 1 };
    std::int64_t index = cb::permutation_index(p);
    std::vector<int> p2 = cb::index_permutation(5, index);
    std::cout <<
        "simple round trip:" << std::endl <<
        "  original:   " << p << std::endl <<
        "  round trip: " << p2 << std::endl <<
        "  index: " << index << std::endl;
}

void print_permutations(int n)
{
    std::int64_t num_permutations = cb::factorial(n);

    for (std::int64_t i = 0; i < num_permutations; ++i) {
        std::vector<int> p = cb::index_permutation(n, i);
        std::cout << p << std::endl;
    }
}


void test_big_round_trip(int n)
{
    std::int64_t num_permutations = cb::factorial(n);

    for (std::int64_t index = 0; index < num_permutations; ++index) {
        std::vector<int> p = cb::index_permutation(n, index);
        std::int64_t index2 = cb::permutation_index(p);
        if (index != index2) {
            std::cout <<
                "ERROR: problem with big round trip:" << std::endl <<
                "index: " << index << std::endl <<
                "permutation: " << p << std::endl <<
                "index2: " << index2 << std::endl;
        }
    }
}


int main() {
    simple_round_trip();
    print_permutations(4);
    test_big_round_trip(8);
    return 0;
}
