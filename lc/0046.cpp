// 0046. Permutations
// Problem definition: https://leetcode.com/problems/permutations/
// Accepted 2021-08-10
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<int> nums_prev = nums;
        std::vector<std::vector<int>> result(1, nums);
        while (std::prev_permutation(nums_prev.begin(), nums_prev.end())) {
            result.push_back(nums_prev);
        }
        while (std::next_permutation(nums.begin(), nums.end())) {
            result.push_back(nums);
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<std::vector<int>>>> input {
        {{1,2,3},{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
        {{0,1},{{0,1},{1,0}}}, {{1},{{1}}},
        {{3,2,1},{{3,2,1},{3,1,2},{2,3,1},{2,1,3},{1,3,2},{1,2,3}}},
        {{2,3,1},{{2,3,1},{2,1,3},{3,2,1},{3,1,2},{1,2,3},{1,3,2}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.permute(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
