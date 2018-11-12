// Problem definition: https://uva.onlinejudge.org/external/105/10567.pdf
// Accepted: ?

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string candidates;
    std::cin >> candidates;

    std::vector<std::vector<int>> serials {123};

    for (int i = 0; i < candidates.size(); ++i)
    {
        serials[candidates[i]].push_back(i);
    }

    int queryCount {0};
    std::cin >> queryCount;

    while (queryCount--)
    {
        std::string query;
        std::cin >> query;

        std::cout << query << "\n";
    }
}