// 0304. Range Sum Query 2D - Immutable
// Problem definition: https://leetcode.com/problems/range-sum-query-2d-immutable/
// Accepted 2021-09-30
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) : 
        m_sums(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1)) {
        for (size_t i {0}; i < matrix.size(); ++i) {
            for (size_t j {0}; j < matrix[0].size(); ++j) {
                m_sums[i+1][j+1] = m_sums[i+1][j] + m_sums[i][j+1] + matrix[i][j] - m_sums[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_sums[row2 + 1][col2 + 1] - m_sums[row1][col2 + 1] - 
            m_sums[row2 + 1][col1] + m_sums[row1][col1];
    }

private:
    std::vector<std::vector<int>> m_sums;
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
