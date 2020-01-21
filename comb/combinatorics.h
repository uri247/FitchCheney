#pragma once
#include <vector>
#include <functional>


template<typename ty, int N>
struct CompileTimeFactorial {
    static constexpr ty value = N * CompileTimeFactorial<ty, N - 1>::value;

};

template<typename ty>
struct CompileTimeFactorial<ty, 0> {
    static constexpr ty value = static_cast<ty>(1);
};

template<int N> using CompileTimeFactorial32 = CompileTimeFactorial<int32_t, N>;
template<int N> using CompileTimeFactorial64 = CompileTimeFactorial<int64_t, N>;


template<typename ty, int N, int K>
struct NChooseK {
    static_assert(N > K);
    static constexpr ty value = NChooseK<ty, N-1, K>::value + NChooseK<ty, N-1, K-1>::value;
};

template<typename ty, int N>
struct NChooseK<ty, N, 0> {
    static constexpr ty value = static_cast<ty>(1);
};

template<typename ty, int N>
struct NChooseK<ty, N, N> {
    static const ty value = static_cast<ty>(1);
};


void iter_combinations(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit);


template<typename ty>
void iter_combinations(const std::vector<ty>& pool, int r, const std::function<void(const std::vector<int>& indices)>& visit)
{
    std::vector<ty> combination(r);
    iter_combinations(pool.size(), [combination, pool](std::vector<int>& indices) {
        for(int index=0; index<4; ++index) {
            combination[index] = pool[indices[index]];
        }
    });
}
