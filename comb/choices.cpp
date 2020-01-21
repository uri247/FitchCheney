#include <vector>
#include <functional>


void iter_combinations(int n, int r, const std::function<void(const std::vector<int>& indices)>& visit)
{
    std::vector<int> indices(r);
    for(int i=0; i<r; ++i) {
        indices[i] = i;
    }

    while (true) {
        visit(indices);
        int pointer;
        for (pointer = r - 1; pointer >= 0; --pointer) {
            int limit_for_pointer = n - r + pointer;
            if (indices[pointer] < limit_for_pointer) {
                break;
            }
        }
        if (pointer < 0) {
            return;
        }
        for (int v = indices[pointer] + 1; pointer < r; ++pointer, ++v) {
            indices[pointer] = v;
        }
    }
}

