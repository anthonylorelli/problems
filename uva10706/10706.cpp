// Problem definition: https://uva.onlinejudge.org/external/107/10706.pdf
// Accepted ?

#include <algorithm>
#include <iostream>
#include <vector>

int NumberOfDigits(long long n)
{
    int count {0};

    do
    {
        n /= 10;
        count++;
    } 
    while (n != 0);

    return count;
}

void GenerateLengths(std::vector<long long>& lengths)
{
    int count {1};
    constexpr int max {2147483647};

    lengths.push_back(0);
    lengths.push_back(1);

    for (int i = 2; lengths[i - 1] <= max; ++i)
    {
        int length = NumberOfDigits(i);
        count += length;
        lengths.push_back(count + lengths[i - 1]);
        //std::cout << lengths[i] << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cases {0};
    std::cin >> cases;

    std::vector<long long> lengths;
    GenerateLengths(lengths);

    while (cases--)
    {
        int target {0};
        std::cin >> target;

        auto offset = std::lower_bound(lengths.begin(), lengths.end(), target);
        auto index = offset - lengths.begin();

        std::cout << "Index: " << index << "\n";

        int next {1};
        int nextLength {1};

        for (int nextLength {1}; index > nextLength; nextLength = NumberOfDigits(++next)) 
        { 
            index -= nextLength;
        }

        index = nextLength - index + 1;

        int value {0};

        while (index--)
        {
            value = next % 10;
            next /= 10;
        }

        std::cout << value << "\n";
    }
}
