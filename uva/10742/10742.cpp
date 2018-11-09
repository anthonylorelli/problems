// Problem definition: https://uva.onlinejudge.org/external/107/10742.pdf
// Accepted ?

#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

void GeneratePrimes(std::vector<int>& primes)
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
            primes.push_back(i);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::vector<int> primes;
    GeneratePrimes(primes);

    int price {0};
    int count {1};
    
    while ((std::cin >> price) && price)
    {
        auto limit = std::lower_bound(primes.begin(), primes.end(), price);
        limit--;

        size_t combinations {0};

        for (size_t i = limit - primes.begin(); i > 0; --i)
        {
            //std::cout << "Current prime: " << primes[i] << "\n";
            if (primes[i] < (price - 1))
            {
                auto j = i - 1; 
                for (;(primes[i] + primes[j]) > price; --j) { /*std::cout << "Lesser prime: " << *current-- << "\n";*/ }
                //std::cout << "Remaining: " << j << "\n";
                combinations += (j + 1);
            }
        }

        std::cout << "Case #" << count++ << ": " << combinations << "\n";
    }
}
