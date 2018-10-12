// Problem definition:
// https://uva.onlinejudge.org/external/110/11057.pdf

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int count {0};
    std::vector<int> prices;

    while (std::cin >> count)
    {
        for (int i = 0; i < count; ++i)
        {
            int p {0};
            std::cin >> p;
            prices.push_back(p);
        }

        int target {0};
        std::cin >> target;

        std::sort(prices.begin(), prices.end());

        constexpr int maxValue {1000001};
        std::pair<int, int> couple {0, maxValue};

        for (const auto p : prices)
        {
            int diff {target - p};
            auto b = std::lower_bound(prices.begin(), prices.end(), diff);

            if (b != prices.end())
            {
                if (std::abs(p - *b) < std::abs(couple.second - couple.first))
                {
                    couple.first = p;
                    couple.second = *b;
                }
            }
        }

        if (couple.first > couple.second) { std::swap(couple.first, couple.second); }
        std::cout << "Peter should buy books whose prices are " << couple.first << 
            " and " << couple.second << "\n\n";
    }
}
