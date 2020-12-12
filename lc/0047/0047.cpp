// 0047. Permutations II
// Problem definition: https://leetcode.com/problems/permutations-ii/
// Accepted 2020-12-11
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    // std::vector<std::pair<std::string,int>> input {
    //     {"3+2*2", 7},
    //     {"3/2", 1},
    //     {"3+5 / 2", 5},
    //     {"3", 3},
    //     {"1/2", 0},
    //     {"1-1+1", 1},
    //     {"0-2147483647",-2147483647}
    // };

    // SECTION("LC test cases") {
    //     std::for_each(std::begin(input), std::end(input),
    //         [&input](auto& p) {
    //             Solution s;
    //             auto& [testInput, expected] = p;
    //             REQUIRE(s.calculate(testInput) == expected);
    //         });
    // }
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
