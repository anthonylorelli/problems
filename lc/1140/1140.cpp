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
        int n = piles.size();
        m_sum.resize(n);
        m_dp.resize(n);
        for(int i=0;i<n;i++) {
            m_dp[i].resize(n);
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                m_dp[i][j] = -1; 
            }
        }
        
        m_sum[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) {
            m_sum[i] = m_sum[i+1] + piles[i];
        }
            
        return find_solution(piles, 0, n, 1);
    }

private:
    int find_solution(std::vector<int>& arr, int index, int n, int X){
        if (index >= n) { return 0; }
        if (m_dp[index][X] != -1) { return m_dp[index][X]; }
        
        int min_value = m_sum[index];
        for (int k=index; k< index + 2 * X && k <n ; k++){
            min_value = std::min(min_value, find_solution(arr, k+1, n, std::max(k-index+1, X)));
        }
        m_dp[index][X] = m_sum[index] - min_value;
        return m_dp[index][X];
    }

    std::vector<int> m_sum;
    std::vector<std::vector<int>> m_dp;
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
