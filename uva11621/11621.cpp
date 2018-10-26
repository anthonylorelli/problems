// Problem definition:
// https://uva.onlinejudge.org/external/116/11621.pdf
// Accepted 2018-10-25

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    constexpr int max {2147483647};
    std::vector<long long> factors;

    for (long long i {1}; i <= max; i *= 2)
    {
        factors.push_back(i);

        for (long long j {1}; j <= max; j *= 3)
        {
            long long k = i * j;

            if (k > max) { break; }

            factors.push_back(k); 
        }
    }

    for (long long i {3}; i <= max; i *= 3)
    {
        factors.push_back(i);
    }

    std::sort(factors.begin(), factors.end());

    int m {0};

    while (std::cin >> m && m != 0)
    {
        auto next = std::lower_bound(factors.begin(), factors.end(), m);

        if (next != factors.end())
        {
            std::cout << *next << "\n";
        }
    }
}
