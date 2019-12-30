// 1029. Two City Scheduling
// Problem definition: https://leetcode.com/problems/two-city-scheduling/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Two City Scheduling]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{10,20},{30,200},{400,50},{30,20}},110}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.twoCitySchedCost(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
