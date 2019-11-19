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
    int getMoneyAmount(T& t, int left, int right) {
        if (t[left][right]) {
            return t[left][right];
        }

        if (left >= right) {
            return 0;
        } else if (left >= (right - 2)) {
            return right - 1;
        }

        int mid {left + (right - left) / 2}, min {std::numeric_limits<int>::max()};

        for (int i {mid}; i < right; ++i) {
            min = std::min(min, i + std::max(getMoneyAmount(t, i + 1, right), getMoneyAmount(t, left, i - 1)));
        }

        t[left][right] = min;

        return min;
    }

    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> table{n+1u, std::vector<int>(n+1u, 0)};
        return getMoneyAmount(table, n, 1);
    }
};

TEST_CASE("LC test cases", "[Guess Number Higher or Lower II]") {
    Solution s;
    std::vector<std::pair<int,int>> input {
        {{10,21},{1,0},{3,2}}
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
