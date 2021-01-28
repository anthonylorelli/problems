// 0062. Unique Paths
// Problem definition: https://leetcode.com/problems/unique-paths/
// Accepted 2021-01-27
// Cf. https://leetcode.com/problems/unique-paths/discuss/391856/c%2B%2B-backtracking-to-2D-DP-and-finally-1D-DP
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int32_t> dp(n, 1);
        for (int32_t i {1}; i < m; ++i) {
            for (int32_t j {1}; j < n; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp.back();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int,int>> input {
        {3,7,28},
        {3,2,3},
        {7,3,28},
        {3,3,6}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [m, n, expected] = p;
                REQUIRE(s.uniquePaths(m, n) == expected);
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
