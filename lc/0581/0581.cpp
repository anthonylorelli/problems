// 0581. Shortest Unsorted Continuous Subarray
// Problem definition: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        using namespace std::placeholders;
        auto p1 = std::adjacent_find(nums.begin(), nums.end(), std::greater<int>());
        auto min = p1 != nums.end() ? *std::min_element(p1 + 1, nums.end()) : nums[0];
        auto p2 = std::adjacent_find(nums.rbegin(), nums.rend(), std::less<int>());
        auto max = p2 != nums.rend() ? *std::max_element(p2 + 1, nums.rend()) : *nums.rbegin();
        auto start = std::find_if(nums.begin(), p1 + 1, std::bind(std::less<int>(), _1, min));
        auto end = std::find_if(nums.rbegin(), p2 + 1, std::bind(std::greater(), _1, max));
        return (nums.rend() - end) - (start - nums.begin());
    }
};

TEST_CASE("LC test cases", "[Shortest Unsorted Continuous Subarray]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2, 6, 4, 8, 10, 9, 15},5},{{8,9,10,1,2,3,4,5,6,7},10}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findUnsortedSubarray(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
