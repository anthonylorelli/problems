// 0581. Shortest Unsorted Continuous Subarray
// Problem definition: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Shortest Unsorted Continuous Subarray]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2, 6, 4, 8, 10, 9, 15},5}
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
