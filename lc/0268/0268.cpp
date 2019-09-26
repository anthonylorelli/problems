// 0268. Missing Number
// Problem definition: https://leetcode.com/problems/missing-number/
// Accepted 2019-09-25

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        size_t missing {nums.size()};
        for (size_t i {0}; i < nums.size(); ++i) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }

    int missingNumberIndexAlignment(std::vector<int>& nums) {
        for (size_t i {0}; i < nums.size(); ++i) {
            auto current {nums[i]};
            if (current < nums.size() && i != current) {
                std::swap(nums[i], nums[current]);
                if (nums[i] != nums[current]) { --i; }
            }
        }

        for (size_t i {0}; i < nums.size(); ++i) {
            if (nums[i] != i) { return i; }
        }

        return nums.size();
    }
};

TEST_CASE("LC test cases", "[Missing Number]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,int>> input {
        {{},0}, {{3, 0, 1}, 2}, {{9,6,4,2,3,5,7,0,1}, 8}, {{1}, 0},
        {{0}, 1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.missingNumber(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
