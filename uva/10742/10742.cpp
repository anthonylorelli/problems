// Problem definition: https://uva.onlinejudge.org/external/107/10742.pdf
// Accepted ?

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

void GeneratePrimes(std::vector<int>& numbers)
{
    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    constexpr int max {1000001};
    std::bitset<max> sieve;

    sieve.set();
    sieve[0] = 0;
    sieve[1] = 0;
    
    for (int i = 2; i < max; ++i)
    {
        if (sieve[i])
        {
            for (int j = 1; i + (j * i) < max; ++j) { sieve[i + (j * i)] = 0; }
            numbers.push_back(i);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::vector<int> numbers;
    GeneratePrimes(numbers);

    //for (auto i : numbers) { std::cout << i << "\n"; }

    int price {0};
    int count {1};
    
    while (std::cin >> price && price)
    {
        auto bound = std::lower_bound(numbers.begin(), numbers.end(), price);

        int combinations {0};
        int last {*bound};

        while (*(--bound) + last > price) { }

        auto remaining = bound - numbers.begin();

        std::cout << "Case #" << count++ << ": " << combinations << "\n";
    }
}
