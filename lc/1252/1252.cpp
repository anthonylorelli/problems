// 1252. Cells with Odd Values in a Matrix
// Problem definition: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <tuple>

class Solution {
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Maximum Width Ramp]") {
    std::vector<std::tuple<int,int,std::vector<std::vector<int>>,int>> input {
        {2,3,{{0,1},{1,1}},6}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                // auto& [testInput, expected] = p;
                // REQUIRE(s.maxWidthRamp(testInput) == expected);
                auto& [n,m,matrix,expected] = p;
                REQUIRE(s.oddCells(n,m,matrix) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
