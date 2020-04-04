// 0962. Maximum Width Ramp
// Problem definition: https://leetcode.com/problems/maximum-width-ramp/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& A) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Maximum Width Ramp]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{6,0,8,2,1,5},4},{{9,8,1,0,1,9,4,0,4,1},7}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxWidthRamp(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
