// Problem definition:
// https://uva.onlinejudge.org/external/106/10611.pdf

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int heights {0};
    std::cin >> heights;

    std::vector<int> heightList;

    for (int i = 0; i < heights; ++i)
    {
        int h;
        std::cin >> h;
        heightList.push_back(h);
    }

    int luchuHeights {0};
    std::cin >> luchuHeights;

    std::vector<int> luchuList;

    for (int i = 0; i < luchuHeights; ++i)
    {
        int h;
        std::cin >> h;
        luchuList.push_back(h);
    }

    for (const int h : luchuList)
    {
        auto lower = std::lower_bound(heightList.begin(), heightList.end(), h);

        if (lower == heightList.begin()) 
        {
            std::cout << "X";
        }
        else if (lower == heightList.end())
        {
            auto v = *(lower - 1);
            if (v < h) std::cout << v;
            else std::cout << "X";
        }
        else
        {
            std::cout << *(lower - 1);
        }

        auto upper = std::upper_bound(heightList.begin(), heightList.end(), h);

        if (upper == heightList.end())
        {
            std::cout << " X\n";
        }
        else
        {
            std::cout << " " << *upper << "\n";
        }
    }
}
