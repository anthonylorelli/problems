// 0304. Range Sum Query 2D - Immutable
// Problem definition: https://leetcode.com/problems/range-sum-query-2d-immutable/
// Accepted 2021-09-30
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <memory>
#include <numeric>

class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) : 
        m_sums{std::make_unique<std::vector<std::vector<int>>>(matrix.size(), 
            std::vector<int>(matrix[0].size()))} {
        for (size_t i {0}; i < matrix.size(); ++i) {
            std::partial_sum(matrix[i].begin(), matrix[i].end(), (*m_sums)[i].begin());
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int32_t sum {0};
        for (int32_t i {row1}; i <= row2; ++i) {
            int32_t row = (*m_sums)[i].back();
            int32_t left = col1 ? (*m_sums)[i][col1 - 1] : 0;
            int32_t right = row - (*m_sums)[i][col2];
            sum += row - left - right;
        }
        return sum;
    }

private:
    std::unique_ptr<std::vector<std::vector<int>>> m_sums;
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int>> input {
//         {{7,1,5,3,6,4},5},{{7,6,4,3,1},0}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.maxProfit(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
