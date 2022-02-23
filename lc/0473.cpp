// 0473. Matchsticks to Square
// Problem definition: https://leetcode.com/problems/matchsticks-to-square/
// Accepted 2021-02-28
// Cf. https://leetcode.com/problems/matchsticks-to-square/discuss/491204/4ms-C%2B%2B-DFS-with-pruning
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    bool makesquare(std::vector<int>& nums) {
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) { return false; }
        std::sort(nums.begin(), nums.end(), [](const auto a, const auto b) { return a > b; });
        return dfs(nums, 0, 0, sum / 4, 0);
    }

private:
    bool dfs(const std::vector<int>& nums, const int sum, const int status, 
        const int target, const int side) {
        const int n = nums.size();
        if (status == (1 << n) - 1) { return side == 4; }

        for (int i {0}; i < n; ++i) {
            if (status & (1 << i)) { continue; }
            int nextSum {sum};
            int nextSide {side};
            if (sum + nums[i] > target) { return false; }
            nextSum = sum + nums[i] == target ? ++nextSide, 0 : sum + nums[i];
            if (dfs(nums, nextSum, status | (1 << i), target, nextSide)) { return true; }
        }

        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,bool>> input {
        {{1,1,2,2,2},true},
        {{3,3,3,3,4},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.makesquare(testInput) == expected);
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
