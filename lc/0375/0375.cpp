// 0375. Guess Number Higher or Lower II
// Problem definition: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Accepted ?
// Cf. https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84799/java-MinMax-solution-beats-97

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <limits>

class Solution {
public:
    template <typename T>
    int getMoneyAmount(T& t, int row, int col) {
        if (t[row][col]) {
            return t[row][col];
        }

        if (row >= col) {
            return 0;
        } else if (row >= (col - 2)) {
            return col - 1;
        }

        int mid {row + (col - row) / 2}, min {std::numeric_limits<int>::max()};

        for (int i {mid}; i < col; ++i) {
            min = std::min(min, i + std::max(getMoneyAmount(t, i + 1, col), getMoneyAmount(t, row, i - 1)));
        }

        t[row][col] = min;

        return min;
    }

    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> table{n+1u, std::vector<int>(n+1u, 0)};
        return getMoneyAmount(table, 1, n);
    }
};

TEST_CASE("LC test cases", "[Guess Number Higher or Lower II]") {
    Solution s;
    std::vector<std::pair<int,int>> input {
        {{10,16},{1,0},{3,2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.getMoneyAmount(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
