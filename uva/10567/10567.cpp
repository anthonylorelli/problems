// Problem definition: https://uva.onlinejudge.org/external/105/10567.pdf
// Accepted: ?

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

        constexpr int invalidSerial {-1};
        int first {invalidSerial};
        int next {invalidSerial};
        bool found {true};

        for (size_t i = 0; i < query.size(); ++i)
        {
            auto current = std::upper_bound(serials[query[i]].begin(), serials[query[i]].end(), next);
            if (current == serials[query[i]].end())
            {
                found = false;
                break;
            }
            else
            {
                auto offset = current - serials[query[i]].begin();
                next = serials[query[i]][offset];
                if (i == 0) { first = next; }
            }
        }

        if (found) 
        { 
            std::cout << "Matched " << first << " " << next << "\n"; 
        }
        else 
        { 
            std::cout << "Not matched" << "\n"; 
        }
    }
}