// 0464. Can I Win
// Problem definition: https://leetcode.com/problems/can-i-win/
// Accepted ?
// Cf. https://leetcode.com/problems/can-i-win/discuss/95320/Clean-C%2B%2B-beat-98.4-DFS-with-early-termination-check-(detailed-explanation)
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int32_t sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (desiredTotal < 2) {
            return true;
        }
        if (sum < desiredTotal) {
            return false;
        }
        if (sum == desiredTotal) {
            return is_odd(maxChoosableInteger);
        }
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }

private:
    constexpr bool is_odd(int32_t n) {
        return n & 1;
    }

    bool dfs(int m, int t, int k) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int, bool>> input {
        {10, 11, false}, {10, 0, true}, {10, 1, true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [max, desired, expected] = p;
                REQUIRE(s.canIWin(max, desired) == expected);
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
