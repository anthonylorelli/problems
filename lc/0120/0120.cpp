// 0120. Triangle
// Problem definition: https://leetcode.com/problems/triangle/
// Accepted 2020-12-29
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
        {{{2},{3,4},{6,5,7},{4,1,8,3}},11},
        {{{-10}},-10},
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                auto& [array, target] = testInput;
                REQUIRE(s.search(array, target) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
