// Problem definition: https://uva.onlinejudge.org/external/114/11498.pdf
// Accepted ?

#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int queries {0};

    while (std::cin >> queries && queries != 0)
    {
        std::pair<int, int> origin {0, 0};
        std::cin >> origin.first >> origin.second;

        std::vector<std::pair<int, int>> residences;

        while (queries--)
        {
            std::pair<int, int> coordinates;
            std::cin >> coordinates.first >> coordinates.second;
            residences.push_back(coordinates);
        }

        for (const auto& c : residences)
        {
            std::cout << c.first << " " << c.second << "\n";
        }
    }
}
