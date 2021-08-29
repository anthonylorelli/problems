// 1140. Stone Game II
// Problem definition: https://leetcode.com/problems/stone-game-ii/
// Accepted 2020-12-23
// Cf. https://leetcode.com/problems/stone-game-ii/discuss/919472/C%2B%2B-Easy-DP-top-down-%2B-prefix-sums
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        const int n = piles.size();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));
        std::vector<int> presum(piles.begin(), piles.end());
        std::partial_sum(presum.rbegin(), presum.rend(), presum.rbegin());
        return dfs(piles, 1, 0, presum, memo);
    }

private:
    int dfs(const std::vector<int>& piles, const int m, const int p, 
        const std::vector<int>& presum, std::vector<std::vector<int>>& memo) const {
        if (p+2*m >= piles.size()) { return presum[p]; }
        if (memo[p][m] > 0) { return memo[p][m]; }

        int res=0;
        for (int i = 1; i <= 2*m; ++i) {
            res = std::max(res, presum[p] - dfs(piles, std::max(i,m), p+i, presum, memo));
        }
        return memo[p][m] = res;
    }
};

class Solution1 {
public:
    int stoneGameII(std::vector<int>& piles) {
        std::vector<int> sums = {0};
        std::partial_sum(piles.begin(), piles.end(), std::back_inserter(sums));
        std::vector<std::vector<int>> dp(sums.size(), std::vector<int>(2 * sums.size() + 1, -1));
        return dfs(1, 1, sums, dp);
    }

private:
    int dfs(const int i, const int m, const std::vector<int>& sums, std::vector<std::vector<int>>& dp) {
        if (i == sums.size()) { return 0; }
        if (dp[i][m] != -1) { return dp[i][m]; }

        int result {0};
        for (int n {0}; n < 2 * m && n + i < sums.size(); ++n) {
            result = std::max(result, sums.back() - sums[i - 1] - 
                dfs(i + n + 1, std::max(m, n + 1), sums, dp));
        }
        return dp[i][m] = result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2,7,9,4,4},10},
        {{1,2,3,4,5,100},104}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.stoneGameII(testInput) == expected);
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
