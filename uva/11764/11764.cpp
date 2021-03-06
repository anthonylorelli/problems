// Problem definition: https://uva.onlinejudge.org/external/117/11764.pdf
// Accepted 2019-01-29

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    for (int caseNum = 1; caseNum <= cases; ++caseNum)
    {
        int walls {0};
        std::vector<int> heights;

        std::cin >> walls;

        while (walls--)
        {
            int height {0};
            std::cin >> height;
            heights.push_back(height);
        }

        int highJumps {0};
        int lowJumps {0};

        for (size_t i = 1; i < heights.size(); ++i)
        {
            if (heights[i] > heights[i-1])
            {
                highJumps++;
            }
            else if (heights[i] < heights[i-1])
            {
                lowJumps++;
            }
        }

        std::cout << "Case " << caseNum << ": " << highJumps << " " << lowJumps << "\n";
    }
}
