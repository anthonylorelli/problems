// 0643. Maximum Average Subarray I
// Problem definition: https://leetcode.com/problems/maximum-average-subarray-i/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double average {0.0};
        for (int32_t i {0}, j {0}, sum {0}; i < nums.size(); ++i) {
            sum += nums[i];
            if (i > k) {
                sum -= nums[j++];
            }
        }
        return 0.0;
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
