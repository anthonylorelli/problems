// 0334. Increasing Triplet Subsequence
// Problem definition: https://leetcode.com/problems/increasing-triplet-subsequence/
// Accepted 2021-08-27
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int low {std::numeric_limits<int>::max()}, mid {std::numeric_limits<int>::max()};

        for (const auto n : nums) {
            if (n <= low) {
                low = n;
            } else if (n <= mid) {
                mid = n;
            } else {
                return true;
            }
        }

        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,bool>> input {
        {{1,2,3,4,5},true},{{5,4,3,2,1},false},{{2,1,5,0,4,6},true},
        {{20,100,10,12,5,13},true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.increasingTriplet(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
