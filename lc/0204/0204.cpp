// 0204. Count Primes
// Problem definition: https://leetcode.com/problems/count-primes/
// Accepted 2021-01-25
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> primes = sieve(n);
        return std::count(primes.begin(), primes.end(), true);
    }

private:
    std::vector<bool> sieve(const int n) {
        if (n < 2) {
            return std::vector<bool>(n, false);
        }
        std::vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        for (int32_t i {2}; i * i < n; ++i) {
            if (!primes[i]) { continue; }
            for (int32_t j {i*i}; j < n; j += i) {
                primes[j] = false;
            }
        }
        return primes;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {10,4},
        {0,0},
        {1,0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countPrimes(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
