// Problem definition: https://uva.onlinejudge.org/external/121/12157.pdf
// Accepted 2019-02-01

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int count {0};
    std::cin >> count;

    std::vector<int> cases(count);
    std::iota(cases.begin(), cases.end(), 1);

    for (auto i : cases)
    {
        int callCount {0};
        std::cin >> callCount;
        std::vector<int> calls(callCount);
        std::for_each(calls.begin(), calls.end(), [&](int& n) { std::cin >> n; });

        auto mileCost { std::accumulate(calls.begin(), calls.end(), 0,
            [](const int total, const int call) { return total + ((call / 30) + 1) * 10; })};
        auto juiceCost { std::accumulate(calls.begin(), calls.end(), 0,
            [](const int total, const int call) { return total + ((call / 60) + 1) * 15; })};

        std::cout << "Case " << i << ": ";
        if (mileCost < juiceCost)
        {
            std::cout << "Mile " << mileCost << "\n";
        }
        else if (juiceCost < mileCost)
        {
            std::cout << "Juice " << juiceCost << "\n";
        }
        else
        {
            std::cout << "Mile Juice " << mileCost << "\n";
        }
    }
}
