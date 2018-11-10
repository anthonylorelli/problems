// Problem definition: https://uva.onlinejudge.org/external/107/10742.pdf
// Accepted 2018-11-09

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
        size_t combinations {0};

        if (price > 2)
        {
            auto limit = std::lower_bound(primes.begin(), primes.end(), price);
            limit--;

            for (size_t i = limit - primes.begin(); i > 0; --i)
            {
                if (primes[i] < (price - 1))
                {
                    auto difference = price - primes[i];

                    if (difference >= primes[i])
                    {
                        combinations += i;
                    }
                    else
                    {
                        auto pair = std::lower_bound(primes.begin(), primes.end(), difference);
                        if (*pair != difference) { --pair; }
                        auto j = (pair - primes.begin()) + 1;
                        combinations += j;
                    }
                }
            }
        }

        std::cout << "Case " << count++ << ": " << combinations << "\n";
    }
}
