// 0374. Guess Number Higher or Lower
// Problem definition: https://leetcode.com/problems/guess-number-higher-or-lower/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(const int current, const int max) const noexcept {
        auto result {guess(current)};
        return !result ? current : result == -1 ? guessNumber(current / 2, current) :
            guessNumber(current + current / 2, max);
    }

    int guessNumber(int n) {
        return guessNumber(n / 2, n);
    }
};

TEST_CASE("LC test cases", "[Swim in Rising Water]") {
    Solution s;

    SECTION("LC test cases") {
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
