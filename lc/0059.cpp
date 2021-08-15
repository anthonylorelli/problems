// 0059. Spiral Matrix II
// Problem definition: https://leetcode.com/problems/spiral-matrix-ii/
// Accepted 2021-08-14
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    constexpr int32_t floor_mod(const int32_t x, const int32_t y) {
        return ((x % y) + y ) % y;
    }

    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int>(n));
        int32_t dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int32_t count {1}, d {0}, row {0}, col {0}; count <= n * n; row += dir[d][0], col += dir[d][1]) {
            result[row][col] = count++;
            const int32_t r = floor_mod(row + dir[d][0], n);
            const int32_t c = floor_mod(col + dir[d][1], n);
            if (result[r][c] != 0) { d = (d + 1) % 4; }
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<std::vector<int>>>> input {
        {3,{{1,2,3},{8,9,4},{7,6,5}}},{1,{{1}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.generateMatrix(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
