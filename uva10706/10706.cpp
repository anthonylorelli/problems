// Problem definition:
// https://uva.onlinejudge.org/external/107/10706.pdf
// Accepted ?

#include <iostream>
#include <math.h>
#include <vector>

size_t NumberOfDigits(size_t n)
{
    size_t count {0};

    do
    {
        n /= 10;
        count++;
    } 
    while (n != 0);

    return count;
}

void CalculateLengths(std::vector<size_t>& lengths)
{
    lengths.push_back(1);
    int count {1};
    std::cout << lengths[0] << "\n";
    constexpr int max {2147483647};

    for (int i = 2; lengths[i - 2] <= max; ++i)
    {
        int length = NumberOfDigits(i);
        //std::cout << length << "\n";
        count += length;
        lengths.push_back(count + lengths[i - 2]);
        std::cout << lengths[i - 1] << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    std::vector<size_t> lengths;
    CalculateLengths(lengths);

    while (cases--)
    {
        int target {0};
        std::cin >> target;
    }
}
