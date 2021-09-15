// 0036. Valid Sudoku
// Problem definition: https://leetcode.com/problems/valid-sudoku/
// Accepted 2021-01-04
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <bitset>
#include <iostream>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < board.size(); ++row) {
            std::bitset<10> table;
            if (!checkRow(board, table, row, 0)) { return false; }
        }
        for (int col = 0; col < board[0].size(); ++col) {
            std::bitset<10> table;
            if (!checkColumn(board, table, 0, col)) { return false; }
        }
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                if (!checkGrid(board, i, j)) { return false; }
            }
        }

        return true;
    }

private:
    bool checkColumn(std::vector<std::vector<char>>& board, std::bitset<10>& table, const int row, const int col) {
        if (row == 9) { return true; }
        const char val {board[row][col]};
        if (val == '.') {
            return checkColumn(board, table, row + 1, col);
        }

        const int hash {val - '0'};

        if (table[hash]) {
            return false;
        }

        table[hash] = true;
        return checkColumn(board, table, row + 1, col);
    }

    bool checkRow(std::vector<std::vector<char>>& board, std::bitset<10>& table, const int row, const int col) {
        if (col == 9) { return true; }
        const char val {board[row][col]};
        if (val == '.') {
            return checkRow(board, table, row, col + 1);
        }

        const int hash {val - '0'};

        if (table[hash]) {
            return false;
        } 

        table[hash] = true;
        return checkRow(board, table, row, col + 1);
    }

    bool checkGrid(std::vector<std::vector<char>>& board, const int startY, const int startX) {
        const int xLimit {startX + 3};
        const int yLimit {startY + 3};
        std::bitset<10> table;
        for (int i = startX; i < xLimit; ++i) {
            for (int j = startY; j < yLimit; ++j) {
                const char val {board[j][i]};
                if (val == '.') {
                    continue;
                }
                const int hash {val - '0'};
                if (table[hash]) {
                    return false;
                }
                table[hash] = true;
            }
        }
        return true;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<std::vector<char>>,bool>> input {
        {{{'5','3','.','.','7','.','.','.','.'},
          {'6','.','.','1','9','5','.','.','.'},
          {'.','9','8','.','.','.','.','6','.'},
          {'8','.','.','.','6','.','.','.','3'},
          {'4','.','.','8','.','3','.','.','1'},
          {'7','.','.','.','2','.','.','.','6'},
          {'.','6','.','.','.','.','2','8','.'},
          {'.','.','.','4','1','9','.','.','5'},
          {'.','.','.','.','8','.','.','7','9'}},true},
        {{{'8','3','.','.','7','.','.','.','.'},
          {'6','.','.','1','9','5','.','.','.'},
          {'.','9','8','.','.','.','.','6','.'},
          {'8','.','.','.','6','.','.','.','3'},
          {'4','.','.','8','.','3','.','.','1'},
          {'7','.','.','.','2','.','.','.','6'},
          {'.','6','.','.','.','.','2','8','.'},
          {'.','.','.','4','1','9','.','.','5'},
          {'.','.','.','.','8','.','.','7','9'}},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.isValidSudoku(testInput) == expected);
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
