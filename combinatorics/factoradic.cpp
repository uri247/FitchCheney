#include "combinatorics.h"
#include <vector>
#include <cstdint>

namespace cb {


std::int64_t factorial(int n)
{
	if (n == 0) {
		return 1;
	}
	else {
		return static_cast<std::int64_t>(n)* factorial(n - 1);
	}
}



std::int64_t permutation_index(std::vector<int> perm, int n)
{
	std::int64_t sum = 0;
	std::int64_t num_digits = perm.size();
	if (n == -1) {
		n = num_digits;
	}
	for (std::int64_t i = 0; i < num_digits; ++i) {
		std::int64_t digit = perm[i];
		sum = sum * (n - i) + digit;
		for (std::int64_t j = i + 1; j < num_digits; ++j) {
			if (perm[j] > digit) {
				perm[j] -= 1;
			}
		}
	}
	return sum;
}


std::vector<int> index_permutation(int n, std::int64_t index)
{
	std::vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		perm[i] = i;
	}

	std::int64_t factor = factorial(n - 1);
	for (std::int64_t i = 0; index > 0; ++i) {
		lldiv_t result = std::lldiv(index, factor);
		int digit = static_cast<int>(result.quot);
		std::rotate(perm.begin() + i, perm.begin() + i + digit, perm.begin() + i + digit + 1);
		index = result.rem;
		factor /= n - i - 1;
	}
	return perm;
}

}
