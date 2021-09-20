#include "combinatorics/combinatorics.h"

#include <cassert>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <iostream>
#include <functional>
#include <bitset>
#include <memory>

#if NDEBUG
const int DECK_SIZE = 124;
const int HAND_SIZE = 5;
const int SHOW_SIZE = 4;
#else
const int DECK_SIZE = 27;
const int HAND_SIZE = 4;
const int SHOW_SIZE = 3;
#endif


// Given a specific hand, return the showing of that hand.
std::vector<int>  hands_to_show(const std::vector<int>& hand)
{
    constexpr int info_space = cb::CompileTimeFactorial32<SHOW_SIZE>::value;

#ifndef NDEBUG
    for (auto it = hand.begin(); it != hand.end() - 1; ++it) {
        assert(*it < *(it + 1));
    }
#endif

    int sum = std::accumulate(hand.begin(), hand.end(), 0);
    int excluded_card_index = sum % HAND_SIZE;
    int excluded_card = hand[excluded_card_index];

    // The excluded card index in the "clean" deck, after we removed the 4 cards
    int excluded_card_in_clean_deck = excluded_card - excluded_card_index;
    int information = excluded_card_in_clean_deck / HAND_SIZE;

    // we want to encode information (0-23) with a permutation
    std::vector<int> indices = cb::index_permutation(SHOW_SIZE, information);

    std::vector<int> show(SHOW_SIZE);
    for (int i = 0; i < SHOW_SIZE; ++i) {
        int index_in_info = indices[i];
        if (index_in_info >= excluded_card_index)
            ++index_in_info;
        show[i] = hand[index_in_info];
    }

    return show;
}



class TestByVerifyOnDomain
{
public:
    static constexpr std::int64_t number_of_hands = cb::CompileTimeCombinations64<DECK_SIZE, HAND_SIZE>::value;
    static constexpr std::int64_t number_of_shows = cb::CompileTimePermutations64<DECK_SIZE, SHOW_SIZE>::value;

private:
    void accept_hand(const std::vector<int>& hand);
    std::unique_ptr<std::bitset<number_of_shows>> _p_shows_bitmap;

public:
    TestByVerifyOnDomain();
    void test();
};


TestByVerifyOnDomain::TestByVerifyOnDomain()
    :_p_shows_bitmap{ std::make_unique<std::bitset<number_of_shows>>() }
{
}

void TestByVerifyOnDomain::test()
{
    cb::iter_combinations(DECK_SIZE, HAND_SIZE, [this](const std::vector<int>& combination) {
        this->accept_hand(combination);
    });
    /*
    std::vector<int> v1{ 0, 1, 2, 4 };
    std::vector<int> v2{ 0, 1, 2, 16 };
    this->accept_hand(v1);
    this->accept_hand(v2);
    */
}

void TestByVerifyOnDomain::accept_hand(const std::vector<int>& hand) {
    std::vector<int> show = hands_to_show(hand);
#if !NDEBUG
    std::cout << hand << " --> " << show << std::endl;
#endif
    std::int64_t show_num = cb::permutation_index(std::move(show), DECK_SIZE);
    if( _p_shows_bitmap->test(show_num)) {
        std::cout << "hep hep hep: " << hand << "->" << show << std::endl;
    }
    _p_shows_bitmap->set(show_num);
}


void FitchCheneyTest()
{
    std::cout <<
        "Verifying FitchCheney Magic:" << std::endl <<
        "    DECK_SIZE: " << DECK_SIZE << std::endl <<
        "    HAND_SIZE: " << HAND_SIZE << std::endl <<
        "    SHOW_SIZE: " << SHOW_SIZE << std::endl <<
        "    total number of hands: " << TestByVerifyOnDomain::number_of_hands << std::endl <<
        "    total number of shows: " << TestByVerifyOnDomain::number_of_shows << std::endl;

    if constexpr(TestByVerifyOnDomain::number_of_hands != TestByVerifyOnDomain::number_of_shows) {
        std::cout << "ERROR: domains and target have different size. Aborting" << std::endl;
        return;
    }

    TestByVerifyOnDomain tester{};
    tester.test();

}
