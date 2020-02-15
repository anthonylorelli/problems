// 1053. Previous Permutation With One Swap
// Problem definition: https://leetcode.com/problems/previous-permutation-with-one-swap/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> prevPermOpt1(std::vector<int>& A) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Previous Permutation With One Swap]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{3,2,1},{3,1,2}}, {{1,1,5},{1,1,5}}, {{1,9,4,6,7},{1,7,4,6,9}}, {{3,1,1,3},{1,3,1,3}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.prevPermOpt1(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
