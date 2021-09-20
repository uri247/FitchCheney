#include "combinatorics.h"

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>


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


void simple_sub_permutation()
{
    std::vector<int> p{ 1, 0, 3 };
    std::int64_t index = cb::permutation_index(p, 5);
    std::cout <<
        "sample sub permutation:" << std::endl <<
        "  original: " << p << std::endl <<
        "  index: " << index << std::endl;
}

void print_sub_permutation(int n, int r)
{
    cb::iter_permutations(n, r, [n](const std::vector<int>& perm) {
        std::vector<int> p{ perm };
        std::int64_t index = cb::permutation_index(p, n);
        std::cout << std::setw(5) << index << ": " << p << std::endl;
        });
}

int main() {
    simple_round_trip();
    print_permutations(4);
    test_big_round_trip(8);
    simple_sub_permutation();
    print_sub_permutation(5, 3);
    return 0;
}
