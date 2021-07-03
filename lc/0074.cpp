// 0074. Search a 2D Matrix
// Problem definition: https://leetcode.com/problems/search-a-2d-matrix/
// Accepted 2021-07-02
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        auto row = std::lower_bound(matrix.begin(), matrix.end(), target,
            [](const auto& row, const auto val) {
                return row[0] < val;
            });
        if (row == matrix.end() || ((*row)[0] > target && row != matrix.begin())) {
            row--;
        }
        auto col = std::lower_bound(row->begin(), row->end(), target);
        return !(col == row->end() || *col > target);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,int,bool>> input {
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},3,true},
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},13,false},
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},10,true},
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},23,true},
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},1,true},
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},2,false},
        {{{1}},0,false},
        {{{1,3,5,7},{10,11,16,20},{23,30,34,60}},-10,false},
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.searchMatrix(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
