// 0643. Maximum Average Subarray I
// Problem definition: https://leetcode.com/problems/maximum-average-subarray-i/
// Accepted 2021-05-24
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int32_t sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        int32_t max_sum = sum;
        std::transform(nums.begin() + k, nums.end(), nums.begin(), nums.begin(), 
            [&](const auto a, const auto b) {
                sum = sum + a - b;
                avg = std::max(max_sum, sum);
                return b;
            });
        return max_sum / static_cast<double>(k);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,double>> input {
        {{1,12,-5,-6,50,3},4,12.75000},{{5},1,5.0000}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, k, expected] = p;
                REQUIRE(Solution{}.findMaxAverage(testInput, k) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
