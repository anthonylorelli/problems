// Problem definition: https://uva.onlinejudge.org/external/109/10963.pdf
// Accepted 2019-01-25

#include <iostream>
#include <tuple>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int columns {0};
        std::vector<std::pair<int,int>> pairs;
        std::cin >> columns;

        while (columns--)
        {
            int north {0};
            int south {0};
            std::cin >> north >> south;
            pairs.push_back(std::make_pair(north, south));
        }

        int gap {pairs[0].first - pairs[0].second};
        bool closeable {true};

        for (const auto& g : pairs)
        {
            if ((g.first - g.second) != gap)
            {
                closeable = false;
                break;
            }
        }

        if (i > 0) { std::cout << "\n"; }
        std::cout << (closeable ? "yes\n" : "no\n");
    }
}
