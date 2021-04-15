// 0397. Integer Replacement
// Problem definition: https://leetcode.com/problems/integer-replacement/
// Accepted 2021-04-14
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <limits>

class Solution {
public:
    int integerReplacement(int n) {
        return calculate(n, 0);
    }

private:
    int calculate(int n, int count) {
        if (n == 1) {
            return count;
        }
        if (n == 3) {
            return count + 2;
        }
        if (n == std::numeric_limits<int>::max()) {
            return 32;
        }
        if ((n&1) == 0) {
            return calculate(n >> 1, count + 1);
        }
        if (int next {n+1}; (next & 3) == 0) {
            return calculate(next >> 1, count + 2);
        }
        return calculate(n - 1, count + 1);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,int>> input {
        {8,3}, {7,4}, {4,2}, {std::numeric_limits<int>::max(), 32}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.integerReplacement(testInput) == expected);
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
