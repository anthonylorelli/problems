// Problem definition: https://uva.onlinejudge.org/external/120/12015.pdf
// Accepted 2019-01-30

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    for (int i = 1; i <= cases; ++i)
    {
        constexpr int listLength {10};
        std::vector<std::pair<std::string,int>> results;

        std::string address;
        int relevance;

        for (int i = 0; i < listLength; ++i)
        {
            std::cin >> address >> relevance;
            results.push_back(std::make_pair(address, relevance));
        }

        int topRelevance {0};

        for_each(std::begin(results), std::end(results),
            [&](const std::pair<std::string,int>& p) { if (p.second > topRelevance) { topRelevance = p.second; }});
        std::cout << "Case #" << i << ":\n";
        for_each(std::begin(results), std::end(results),
            [&](const std::pair<std::string,int>& p) { if (p.second == topRelevance) { std::cout << p.first << "\n"; }});
    }
}
