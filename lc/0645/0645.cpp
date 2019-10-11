// 0645. Set Mismatch
// Problem definition: https://leetcode.com/problems/set-mismatch/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::vector<int> result;

        for (int i {0}; i < nums.size(); ++i) {
            int current {nums[i]}, target {i+1};
            if (current != target) {
                std::swap(nums[i], nums[current - 1]);
                if (nums[current - 1] != nums[i]) { --i; }
            }
        }

        for (int i {0}; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                result.push_back(nums[i]);
                result.push_back(i + 1);
                break;
            }
        }

        return result;
    }
};

TEST_CASE("LC test cases", "[Set Mismatch]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{1,2,2,4},{2,3}}, {{3,2,2},{2,1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.findErrorNums(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
