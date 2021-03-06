// Problem definition: https://uva.onlinejudge.org/external/113/11364.pdf
// Accepted 2019-01-12

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};

    std::cin >> cases;

    while (cases--)
    {
        int stores {0};
        int pos {0};
        std::vector<int> positions;

        std::cin >> stores;
        while (stores--) 
        {
            std::cin >> pos;
            positions.push_back(pos);
        }

        int max {0};
        int min {99};

        for (const auto n : positions)
        {
            if (n < min) { min = n; }
            if (n > max) { max = n; }
        }

        std::cout << (max - min) * 2 << "\n";
    }
}
