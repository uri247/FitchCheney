#include <vector>
#include <functional>


void iter_choices(std::function<void(std::vector<int>)> visit)
{
    std::vector<int> v{1, 2, 3};
    visit(v);
}
