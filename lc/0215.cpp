// 0215. Kth Largest Element in an Array
// Problem definition: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,int>> input {
        {{3,2,1,5,6,4},2,5},
        {{3,2,3,1,2,4,5,5,6},4,4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.findKthLargest(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
