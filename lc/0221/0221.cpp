// 0221. Maximal Square
// Problem definition: https://leetcode.com/problems/maximal-square/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.size() == 0) { return 0; }
        std::vector<std::vector<int>> areas {matrix.size(), std::vector(matrix[0].size(), 0)};

        int max {0};
        for (size_t i {0}; i < matrix.size(); ++i) { if (matrix[i][0] == '1') { areas[i][0] = max = 1; } }
        for (size_t i {1}; i < matrix[0].size(); ++i) { if (matrix[0][i] == '1') { areas[0][i] = max = 1; } }
        for (size_t i {1}; i < matrix.size(); ++i) {
            for (size_t j {1}; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    int west {areas[i][j-1]}, north {areas[i-1][j]}, northwest {areas[i-1][j-1]};
                    areas[i][j] = north && west && northwest ? std::min(north, west) + 1 : 1;
                    max = std::max(max, areas[i][j]);
                }
            }            
        }
        return max*max;
    }
};

// [['1','0','1','0','0'],['0','0','0','0',01'],['1','0','1','0','0'],['0','0','0','0','0']]

TEST_CASE("LC test cases", "[Rotate Array]") {
    std::vector<std::pair<std::vector<std::vector<char>>,int>> input {
        {{},0}, {{{'1'}},1}, {{{'0'}},0},
        {{{'1','0','1','0','0'},{'0','0','0','0','0'},{'0','0','0','0','1'},{'0','0','0','0','0'}},1},
        {{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}},4},
        {{{'1','1','1','0','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}},9},
        {{{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','0'}},16},
        {{{'1','0','1','0','0','1','1','1','0'},
          {'1','1','1','0','0','0','0','0','1'},
          {'0','0','1','1','0','0','0','1','1'},
          {'0','1','1','0','0','1','0','0','1'},
          {'1','1','0','1','1','0','0','1','0'},
          {'0','1','1','1','1','1','1','0','1'},
          {'1','0','1','1','1','0','0','1','0'},
          {'1','1','1','0','1','0','0','0','1'},
          {'0','1','1','1','1','0','0','1','0'},
          {'1','0','0','1','1','1','0','0','0'}},4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maximalSquare(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
