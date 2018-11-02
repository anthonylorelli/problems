// Problem definition: https://uva.onlinejudge.org/external/107/10742.pdf
// Accepted ?

#include <iostream>
#include <vector>

void GeneratePrimes(std::vector<int>& numbers)
{
    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    constexpr int max {100};
    std::vector<int> v;

    for (int i = 0; i <= max; ++i) { v.push_back(i); }

    for (int i = 2; i <= max; ++i)
    {
        if (v[i])
        {
            for (int j = 1; i + (j * i) < max; ++j)
            {
                v[i + (j * i)] = 0;
            }
        }
    }

    for (auto i : v) { if (i) { numbers.push_back(i); } }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::vector<int> numbers;
    GeneratePrimes(numbers);

    for (auto i : numbers) { std::cout << i << "\n"; }

    int price {0};
    int count {1};
    
    while (std::cin >> price && price)
    {
        int combinations {0};

        std::cout << "Case #" << count++ << ": " << combinations << "\n";
    }
}
