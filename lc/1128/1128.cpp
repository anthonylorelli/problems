// 1128. Number of Equivalent Domino Pairs
// Problem definition: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Number of Equivalent Domino Pairs]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{1,2},{2,1},{3,4},{5,6}},1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numEquivDominoPairs(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
