#include "combinatorics.h"
#include <iostream>
#include <vector>
#include <cstdint>

#if NDEBUG
static const int DECK_SIZE = 124;
static const int HAND_SIZE = 5;
#else
static const int DECK_SIZE = 52;
static const int HAND_SIZE = 5;
#endif



void test_factorial()
{
    std::cout << "Factorial 10: " << cb::CompileTimeFactorial32<10>::value << std::endl;
}


void accept_combination(const std::vector<int>& comb)
{
    std::cout << comb << std::endl;
}

void test_combinations()
{
    cb::iter_combinations(7, 5, [](const std::vector<int>& comb) {
        std::cout << comb << std::endl;
    });

    int num_iterations = 0;
    cb::iter_combinations(DECK_SIZE, HAND_SIZE, [&num_iterations](const std::vector<int>& comb) {
        ++num_iterations;
    });

    std::cout <<
        "counting:    " << num_iterations << std::endl <<
        "calculating: " << cb::CompileTimeCombinations64<DECK_SIZE, HAND_SIZE>::value << std::endl;
}


void test_permutations()
{
    cb::iter_permutations(5, 3, [](const std::vector<int>& perm) {
        std::cout << perm << std::endl;
    });

    int num_iterations = 0;
    cb::iter_permutations(DECK_SIZE, HAND_SIZE - 1, [&num_iterations](const std::vector<int>& perm) {
        ++num_iterations;
    });
    std::cout <<
        "counting:    " << num_iterations << std::endl <<
        "calculating: " << cb::CompileTimePermutations64<DECK_SIZE, HAND_SIZE - 1>::value << std::endl;
}



int main() {
    std::cout << "testing combinatorics" << std::endl;
    test_factorial();
    test_combinations();
    test_permutations();
    return 0;
}
