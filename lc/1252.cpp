// 1252. Cells with Odd Values in a Matrix
// Problem definition: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Accepted 2020-04-11

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <tuple>
#include <numeric>

class Solution {
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
        std::vector<std::vector<int>> matrix(n, std::vector(m, 0));
        int total {0};
        auto count = [](const int c, int& n) { return c + ((++n % 2) ? 1 : -1); };
        for (const auto& next : indices) {
            int ri {next[0]}, ci {next[1]};
            total = std::accumulate(matrix[ri].begin(), matrix[ri].end(), total, count);
            total = std::accumulate(matrix.begin(), matrix.end(), total,
                [&count, &ci](const int c, auto& v) { return count(c, v[ci]); });
        }
        return total;
    }
};

TEST_CASE("LC test cases", "[Maximum Width Ramp]") {
    std::vector<std::tuple<int,int,std::vector<std::vector<int>>,int>> input {
        {2,3,{{0,1},{1,1}},6},
        {2,2,{{1,1},{0,0}},0}
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
