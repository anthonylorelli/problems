// 0223. Rectangle Area
// Problem definition: https://leetcode.com/problems/rectangle-area/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return 0;        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{-3,0,3,4,0,-1,9,2},45},{{-2,-2,2,2,-2,-2,2,2},16}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [in, expected] = p;
                REQUIRE(s.computeArea(in[0],in[1],in[2],in[3],in[4],in[5],in[6],in[7]) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
