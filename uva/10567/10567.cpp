// Problem definition: https://uva.onlinejudge.org/external/105/10567.pdf
// Accepted: 2018-11-13

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string candidates;
    std::cin >> candidates;

    std::vector<std::vector<int>> serials {123};

    for (size_t i = 0; i < candidates.size(); ++i)
    {
        serials[candidates[i]].push_back(i);
    }

    int queryCount {0};
    std::cin >> queryCount;

    while (queryCount--)
    {
        std::string query;
        std::cin >> query;

        constexpr int maxSerial {1000001};
        int first {maxSerial};
        constexpr int invalidSerial {-1};
        int next {invalidSerial};
        bool matched {true};

        for (const auto c : query)
        {
            auto current = std::upper_bound(serials[c].begin(), serials[c].end(), next);
            if (current == serials[c].end())
            {
                matched = false;
                break;
            }
            else
            {
                auto offset = current - serials[c].begin();
                next = serials[c][offset];
                if (next < first) { first = next; }
            }
        }

        if (matched)
        { 
            std::cout << "Matched " << first << " " << next << "\n"; 
        }
        else 
        { 
            std::cout << "Not matched" << "\n"; 
        }
    }
}