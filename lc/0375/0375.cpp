// 0375. Guess Number Higher or Lower II
// Problem definition: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Accepted 2019-11-19
// Cf. https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84799/java-MinMax-solution-beats-97

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <limits>

class Solution {
public:
    template <typename T>
    int getMoneyAmount(T& t, int begin, int end) {
        if (t[begin][end]) {
            return t[begin][end];
        }

        if (begin >= end) {
            return 0;
        } else if (begin >= (end - 2)) {
            return end - 1;
        }

        int mid {begin + (end - begin) / 2}, min {std::numeric_limits<int>::max()};

        for (int i {mid}; i < end; ++i) {
            min = std::min(min, i + std::max(getMoneyAmount(t, i + 1, end), getMoneyAmount(t, begin, i - 1)));
        }

        t[begin][end] = min;

        return min;
    }

    int getMoneyAmount(int n) {
        unsigned int size {n+1u};
        std::vector table{size, std::vector(size, 0)};
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
