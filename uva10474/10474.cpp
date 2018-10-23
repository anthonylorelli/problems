// Problem definition:
// https://uva.onlinejudge.org/external/104/10474.pdf
// Accepted 2018-10-11

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int numMarbles {0};
    int numQueries {0};
    std::vector<int> marbles;
    int caseNumber {1};

    while ((std::cin >> numMarbles) && (std::cin >> numQueries) && numMarbles && numQueries)
    {
        std::cout << "CASE# " << caseNumber << ":\n";

        for (int i = 0; i < numMarbles; ++i)
        {
            int marble {0};
            std::cin >> marble;
            marbles.push_back(marble);
        }

        std::sort(marbles.begin(), marbles.end());

        for (int i = 0; i < numQueries; ++i)
        {
            int query {0};
            std::cin >> query;
            auto location = std::lower_bound(marbles.begin(), marbles.end(), query);

            if (location == marbles.end() || *location > query)
            {
                std::cout << query << " not found\n";
            }
            else
            {
                auto index = location - marbles.begin();
                std::cout << query << " found at " << index + 1 << "\n";
            }
        }

        marbles.clear();
        caseNumber++;
    }
}
