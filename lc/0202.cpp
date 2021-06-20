// 0202. Happy Number
// Problem definition: https://leetcode.com/problems/happy-number/
// Accepted 2021-06-19
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) { return n; }
        std::unordered_set<int64_t> found = {n};
        for (int64_t i = next(n); i != 1; found.insert(i), i = next(i)) {
            if (found.contains(i)) {
                return false;
            }
        }
        return true;
    }

    constexpr int64_t next(int64_t n) const {
        if (n == 1) { return n; }
        int64_t total {0};
        while (n > 0) {
            int32_t digit {n % 10};
            total += (digit * digit);
            n /= 10;
        }
        return total;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,bool>> input {
        {19,true},{2,false}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.isHappy(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
