// 0473. Matchsticks to Square
// Problem definition: https://leetcode.com/problems/matchsticks-to-square/
// Accepted ?
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
        if (sums % 4) { return false; }
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
