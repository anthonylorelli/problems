// Problem definition: https://uva.onlinejudge.org/external/113/11364.pdf
// Accepted ?

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
    }
}
