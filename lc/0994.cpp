// 0994. Rotting Oranges
// Problem definition: https://leetcode.com/problems/rotting-oranges/
// Accepted 2022-09-13
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

constexpr int c_rotten {2};
constexpr int c_fresh {1};
constexpr int c_empty {0};

class Solution {
private:
    template <typename T, typename U>
    int findStartingPoints(T& grid, U& verts) { 
        int fresh {0};
        for (size_t i {0}; i < grid.size(); ++i) {
            for (size_t j {0}; j < grid[0].size(); ++j) {
                switch (grid[i][j]) {
                case c_rotten:
                    verts.push({i,j});
                    break;
                case c_fresh:
                    fresh++;
                    break;
                }
            }
        }
        return fresh;
    }

public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        const auto max_row {grid.size()};
        const auto max_col {grid[0].size()};
        std::queue<std::pair<size_t,size_t>> verts;
        int minute {-1};
        int turnedRotten {0};
        int fresh = findStartingPoints(grid, verts);

        while (!verts.empty()) {
            minute++;
            const auto next {verts.size()};
            for (size_t i {0}; i < next; ++i) {
                auto [cr, cc] {verts.front()};
                verts.pop();
                for (auto [cx, cy] : {std::pair{cr - 1, cc}, std::pair{cr + 1, cc}, std::pair{cr, cc - 1}, std::pair{cr, cc + 1}}) {
                    if ((cx >=0 && cx < max_row) && (cy >= 0 && cy < max_col) && 
                        (grid[cx][cy] == c_fresh)) {
                        grid[cx][cy] = c_rotten;
                        turnedRotten++;
                        verts.push({cx,cy});
                    }
                }
            }
        }

        return fresh != turnedRotten ? -1 : (minute < 0) ? 0 : minute;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,int>> input {
        {{{2,1,1},{1,1,0},{0,1,1}},4},
        {{{2,1,1},{0,1,1},{1,0,1}},-1},
        {{{0,2}},0},
        {{{0}},0},
        {{{1}},-1},
        {{{2}},0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.orangesRotting(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
