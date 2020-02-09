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
        for (size_t i {0}; i < matrix.size(); ++i) {
            for (size_t j {0}; j < matrix[0].size(); ++j) {
                if (i == 0 || j == 0) {
                    int area {matrix[i][j] - '0'};
                    max = std::max(max, area);
                    areas[i][j] = area;
                } else if (matrix[i][j] == '1') {
                    areas[i][j] = std::min({areas[i][j-1], areas[i-1][j-1], areas[i-1][j]}) + 1;
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
