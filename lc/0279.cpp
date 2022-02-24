// 0279. Perfect Squares
// Problem definition: https://leetcode.com/problems/perfect-squares/
// Accepted 2021-01-24
// Cf. https://leetcode.com/problems/perfect-squares/discuss/725325/C%2B%2B-Bottom-Up-or-Top-Down-Dynamic-Programming
// Legendre's Three-Square Theorem: https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int numSquares(int n) { // Legendre's Three-Square Theorem
        const auto sqrt {std::sqrt(n)};
        if (std::ceil(sqrt) == std::floor(sqrt)) {
            return 1;
        }

        while (n % 4 == 0) {
            n /= 4;
        }

        if (n % 8 == 7) {
            return 4;
        }

        for (int32_t i {1}, sq {1}; sq <= n; ++i, sq = i * i) {
            int32_t delta {n - sq};
            int32_t base = std::sqrt(delta);
            if (base * base == delta) {
                return 2;
            }
        }

        return 3;
    }

    int numSquares_bottom_up(int n) {
        std::vector<int32_t> dp(n+1, std::numeric_limits<int32_t>::max());
        dp[0] = 0;
        for (int32_t sq {1}; sq <= n; ++sq) {
            for (int32_t i {1}; i*i <= sq; ++i) {
                dp[sq] = std::min(dp[sq], dp[sq-(i*i)]+1);
            }
        }
        return dp[n];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {12,3},
        {13,2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numSquares(testInput) == expected);
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
