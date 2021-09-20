#include "combinatorics/combinatorics.h"

#include <cassert>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <iostream>
#include <functional>
#include <map>

const int DECK_SIZE = 27;
const int HAND_SIZE = 4;
const int SHOW_SIZE = 3;



class TestByVerifyOnDomain
{
private:
    void accept_combination(const std::vector<int>& combination);
    static constexpr std::int64_t _number_of_hands = cb::CompileTimeCombinations64<DECK_SIZE, HAND_SIZE>::value;
    static constexpr std::int64_t _number_of_shows = cb::CompileTimePermutations64<DECK_SIZE, SHOW_SIZE>::value;

public:
    TestByVerifyOnDomain();
    void test();
};


TestByVerifyOnDomain::TestByVerifyOnDomain()
{
}

void TestByVerifyOnDomain::test()
{

    cb::iter_combinations(DECK_SIZE, HAND_SIZE, [this](const std::vector<int>& combination) {
        this->accept_combination(combination);
    });
}

void TestByVerifyOnDomain::accept_combination(const std::vector<int>& combination) {
    std::cout << combination << std::endl;
}



void FitchCheneyTest()
{
    std::cout <<
        "Verifying FitchCheney Magic:" << std::endl <<
        "    DECK_SIZE: " << DECK_SIZE << std::endl <<
        "    HAND_SIZE: " << HAND_SIZE << std::endl <<
        "    SHOW_SIZE: " << SHOW_SIZE << std::endl;

    std::int64_t number_of_hands = cb::CompileTimeCombinations64<DECK_SIZE, HAND_SIZE>::value;
    std::int64_t number_of_shows = cb::CompileTimePermutations64<DECK_SIZE, SHOW_SIZE>::value;

    std::cout <<
        "    total number of hands: " << number_of_hands << std::endl <<
        "    total number of shows: " << number_of_shows << std::endl;

    if (number_of_hands != number_of_shows) {
        std::cout << "ERROR: domains and target have different size. Aborting" << std::endl;
        return;
    }

    TestByVerifyOnDomain tester{};
    tester.test();

}



// Given a specific hand, return the showing of that hand
void hands_to_show(std::vector<int>& hand)
{
#ifndef NDEBUG
    for (auto it = hand.begin(); it != hand.end() - 1; ++it) {
        assert(*it < *(it + 1));
    }
#endif

    int sum = std::accumulate(hand.begin(), hand.end(), 0);
    int excluded_card_index = sum % HAND_SIZE;



}