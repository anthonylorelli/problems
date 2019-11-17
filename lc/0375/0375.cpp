// 0375. Guess Number Higher or Lower II
// Problem definition: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Accepted ?
// Cf. https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84799/java-MinMax-solution-beats-97

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 0 || n == 1) { return 0; }
        if (n == 2) { return 1; }
        int lower {1}, upper {n}, sum {0};
        while (lower < upper) {
            int diff {upper - lower};
            if (diff > 5) {
                long total {upper + lower};
                lower = total / 2;
            } else if (diff == 5) {
                lower += 2;
            } else if (diff == 3) {
                return sum + 2;
            }
            sum += lower;
        }
        return sum;
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
