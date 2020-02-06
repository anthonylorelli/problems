// 0832. Flipping an Image
// Problem definition: https://leetcode.com/problems/flipping-an-image/
// 2020-02-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
        for (auto& row : A) { 
            std::reverse(row.begin(), row.end());
            std::transform(row.begin(), row.end(), row.begin(), [](const auto n) { return n ? 0 : 1; });
        }
        return A;
    }
};

TEST_CASE("LC test cases", "[Flipping an Image]") {
    std::vector<std::pair<std::vector<std::vector<int>>,std::vector<std::vector<int>>>> input {
        {{{1,1,0},{1,0,1},{0,0,0}},{{1,0,0},{0,1,0},{1,1,1}}},{{{1}},{{0}}},{{{0}},{{1}}},
        {{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}},{{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.flipAndInvertImage(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
