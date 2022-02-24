// 0209. Minimum Size Subarray Sum
// Problem definition: https://leetcode.com/problems/minimum-size-subarray-sum/
// Accepted 2021-01-22
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <cstdint>
#include <limits>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        int min {std::numeric_limits<int>::max()};
        for (int32_t left {0}, right {0}, sum {0}; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= s) {
                min = std::min(min, right - left + 1); 
                sum -= nums[left++];
            }
        }
        return min == std::numeric_limits<int>::max() ? 0 : min;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<int>,int>> input {
        {7,{2,3,1,2,4,3},2},
        {5,{2,1,1,1,3,2},2},
        {5,{2,1,1,1,1,1,1,2},4},
        {100,{},0},
        {100,{1},0},
        {11,{1,2,3,4,5},3}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [size, testInput, expected] = p;
                REQUIRE(s.minSubArrayLen(size, testInput) == expected);
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
