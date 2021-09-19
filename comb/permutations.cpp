#include "combinatorics.h"
#include <algorithm>

namespace cb {


void iter_permutations_my(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit)
{
    if (r > n) {
        return;
    }

    std::vector<int> indices(n);
    std::vector<int> cycles(r);
    std::vector<int> p(r);

    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    for (int i = 0; i < r; ++i ) {
        cycles[i] = n - i;
    }

    visit(std::vector(indices.begin(), indices.begin() + r));
    while (n) {
        int i;
        for (i = r - 1; i >= 0; --i) {
            cycles[i] -= 1;
            if (cycles[i] == 0) {
                //int tmp = indices[i];
                //std::copy(indices.begin() + i + 1, indices.end(), indices.begin() + i);
                //indices[static_cast<size_t>(n) - 1] = tmp;
                std::rotate(indices.begin() + i, indices.begin() + i + 1, indices.end());
                cycles[i] = n - i;
            }
            else {
                int j = cycles[i];
                std::swap(indices[i], indices[static_cast<size_t>(n) - j]);
                std::copy(indices.begin(), indices.begin() + r, p.begin());
                visit(p);
                break;
            }
        }
        if (i < 0 ) {
            return;
        }
    }
}

void iter_permutations(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit)
{
    iter_permutations_my(n, r, visit);
}



}
