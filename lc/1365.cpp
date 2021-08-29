// 1365. How Many Numbers Are Smaller Than The Current Number
// Problem definition: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Accepted 2020-03-20

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector answer{nums};
        std::sort(nums.begin(), nums.end());
        for (auto& n : answer) {
            auto loc {std::lower_bound(nums.begin(), nums.end(), n)};
            n = loc - nums.begin();
        }
        return answer;
    }
};

TEST_CASE("LC test cases", "[Binary Subarrays With Sum]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{8,1,2,2,3},{4,0,1,1,3}},{{6,5,4,8},{2,1,0,3}},{{7,7,7,7},{0,0,0,0}},
        {{1,2},{0,1}},{{2,1},{1,0}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.smallerNumbersThanCurrent(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
