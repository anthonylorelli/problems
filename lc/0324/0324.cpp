// 0421. Wiggle Sort II
// Problem definition: https://leetcode.com/problems/wiggle-sort-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>
#include <limits>

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        auto average = std::accumulate(nums.begin(), nums.end(), 0) / nums.size();
        auto right = std::partition(nums.begin(), nums.end(), [average](const auto n) { return n <= average; });

    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>>> input {
        {{1,5,1,1,6,4},{1,6,1,5,1,4}},
        {{1,3,2,2,3,1},{2,3,1,3,1,2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                s.wiggleSort(testInput);
                REQUIRE(testInput == expected);
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
