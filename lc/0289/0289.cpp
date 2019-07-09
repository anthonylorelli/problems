// 0289. Game of Life
// Problem definition: https://leetcode.com/problems/game-of-life/
// Accepted ?

/* 
According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using 
the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its 
current state. The next state is created by applying the above rules simultaneously to 
every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
*/

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
private:
    const int countRow(const std::vector<int>& row, const size_t i) const {
        int neighbors{0};
        if (i > 0) {
            if (row[i-1]) { neighbors++; }
        }
        if (row[i]) { neighbors++; }
        if (i+1 < row.size()) {
            if (row[i+1]) { neighbors++; }
        }
        return neighbors;
    }

public:
    void applyRules(std::vector<std::vector<int>>& board,
        const std::vector<std::vector<int>>& neighbors) const {
        for (size_t i{0}; i < board.size(); ++i) {
            for (size_t j{0}; j < board[i].size(); ++j) {
                if (neighbors[i][j] < 2) {
                    board[i][j] = 0;
                } else if (neighbors[i][j] == 3 && !board[i][j]) {
                    board[i][j] = 1;
                } else if (neighbors[i][j] > 3) {
                    board[i][j] = 0;
                }
            }
        }        
    }

    void countNeighbors(std::vector<std::vector<int>>& board,
        std::vector<std::vector<int>>& neighbors) const {
        for (size_t i{0}; i < board.size(); ++i) {
            for (size_t j{0}; j < board[i].size(); ++j) {
                int adjacent{0};
                // Look at row above
                if (i > 0) {
                    adjacent += countRow(board[i-1], j);
                }
                // Look at current row
                adjacent += countRow(board[i], j);
                // Look at row below
                if (i+1 < board.size()) {
                    adjacent += countRow(board[i+1], j);
                }
                neighbors[i][j] = adjacent;
                // If current cell is populated decrement
                if (board[i][j]) { neighbors[i][j]--; }
            }
        }
    }

    void gameOfLife(std::vector<std::vector<int>>& board) {
        size_t rows{board.size()};
        size_t columns{rows > 0 ? board[0].size() : 0};
        std::vector<std::vector<int>> neighbors(rows, std::vector<int>(columns));
        countNeighbors(board, neighbors);
        applyRules(board, neighbors);
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Count neighbors", "[Game of Life]") {
    SECTION("Basic functionality") {
        Solution s;
        std::vector<std::vector<int>> board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
        std::vector<std::vector<int>> neighbors{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        s.countNeighbors(board, neighbors);
        std::vector<std::vector<int>> answer{{1, 1, 2}, {3, 5, 3}, {1, 3, 2}, {2, 3, 2}};
        REQUIRE(neighbors == answer);
    }
    SECTION("Single column") {
        Solution s;
        std::vector<std::vector<int>> board{{0}, {1}, {1}, {1}, {0}, {1}};
        std::vector<std::vector<int>> neighbors{{0}, {0}, {0}, {0}, {0}, {0}};
        s.countNeighbors(board, neighbors);
        std::vector<std::vector<int>> answer{{1}, {1}, {2}, {1}, {2}, {0}};
        REQUIRE(neighbors == answer);
    }
}

TEST_CASE("LC cases", "[Game of Life]") {
    SECTION("Case 1") {
        Solution s;
        std::vector<std::vector<int>> board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
        s.gameOfLife(board);
        std::vector<std::vector<int>> answer{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
        REQUIRE(board == answer);
    }
}
