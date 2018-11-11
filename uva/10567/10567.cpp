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

    int queryCount {0};
    std::cin >> queryCount;

    while (queryCount--)
    {
        std::string query;
        std::cin >> query;

        std::cout << query << "\n";
    }
}