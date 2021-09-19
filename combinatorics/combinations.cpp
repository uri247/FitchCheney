#include "combinatorics.h"
#include <valarray>

namespace cb {

void iter_combinations(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit)
{
    if (r > n) {
        return;
    }

    std::vector<int> indices(r);
    for (int i = 0; i < r; ++i) {
        indices[i] = i;
    }

    visit(indices);

    while (true) {
        int i;
        int j;

        for (i = r - 1; i >= 0; --i) {
            if (indices[i] != n - r + i) {
                break;
            }
        }
        if (i < 0) {
            return;
        }

        indices[i] += 1;
        for (j = i + 1; j < r; ++j) {
            indices[j] = indices[static_cast<size_t>(j) - static_cast<size_t>(1)] + 1;
        }

        visit(indices);
    }
}

}
