#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <cstdint>
#include <array>

namespace cb {

// A function that accept a reference to a vector
using VectorFunction = std::function<void(const std::vector<int>&)>;



template<typename ty, int N>
struct CompileTimeFactorial {
    static constexpr ty value = N * CompileTimeFactorial<ty, N - 1>::value;
};

template<typename ty>
struct CompileTimeFactorial<ty, 0> {
    static constexpr ty value = static_cast<ty>(1);
};

template<int N> using CompileTimeFactorial32 = CompileTimeFactorial<std::int32_t, N>;
template<int N> using CompileTimeFactorial64 = CompileTimeFactorial<std::int64_t, N>;



template<typename ty, int N, int M>
struct CompileTimeCombinations {
    static constexpr ty value = CompileTimeCombinations<ty, N - 1, M - 1>::value + CompileTimeCombinations<ty, N - 1, M>::value;
};

template<typename ty, int N>
struct CompileTimeCombinations<ty, N, 0> {
    static constexpr ty value = 1;
};

template<typename ty, int M>
struct CompileTimeCombinations<ty, M, M> {
    static constexpr ty value = 1;
};

template<int N, int M> using CompileTimeCombinations32 = CompileTimeCombinations<std::int32_t, N, M>;
template<int N, int M> using CompileTimeCombinations64 = CompileTimeCombinations<std::int64_t, N, M>;


template<typename ty, int N, int M>
struct CompileTimePermutations {
    static constexpr ty value = N * CompileTimePermutations<ty, N - 1, M - 1>::value;
};

template<typename ty, int N>
struct CompileTimePermutations<ty, N, 0> {
    static constexpr ty value = 1;
};

template<int N, int M> using CompileTimePermutations32 = CompileTimePermutations<std::int32_t, N, M>;
template<int N, int M> using CompileTimePermutations64 = CompileTimePermutations<std::int64_t, N, M>;


void iter_combinations(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit);
void iter_permutations(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit);



template<typename ty>
void stream_vector(std::ostream& os, typename std::vector<ty>::const_iterator begin, typename std::vector<ty>::const_iterator end)
{
    os << '[';
    for (auto p = begin; p != end; ++p)
    {
        os << *p;
        if (p + 1 != end) {
            os << ", ";
        }
    }
    os << ']';
}

std::int64_t factorial(int n);
std::int64_t permutation_index(std::vector<int> perm);
std::vector<int> index_permutation(int n, std::int64_t index);


}



template<typename ty>
std::ostream& operator<<(std::ostream& os, const std::vector<ty>& vector) {
    cb::stream_vector<ty>(os, vector.begin(), vector.end());
    return os;
}

