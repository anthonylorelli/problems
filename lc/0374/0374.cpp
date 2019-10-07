// 0374. Guess Number Higher or Lower
// Problem definition: https://leetcode.com/problems/guess-number-higher-or-lower/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <tuple>
#include <vector>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int start, int end) {
		if (start == end) { return start; }
        int mid {(end - start) / 2};
        int value {start + (mid == 0 ? 1 : mid)};
        int result {guess(value)};
        return result == 0 ? value : result == -1 ? guessNumber(value, end) : guessNumber(start, value);
    }

    int guessNumber(int n) {
        return guessNumber(1, n);
    }
};

int g_target {0};

int guess(int num) {
    return num == g_target ? 0 : num < g_target ? -1 : 1;
}

TEST_CASE("LC test cases", "[Guess Number Higher or Lower]") {
    Solution s;
    std::vector<std::pair<int,int>> input {
        {10,6}, {1,1}, {2,2}
    };

    SECTION("LC test cases") {
		std::for_each(std::begin(input), std::end(input),
			[&s, &input](auto& p) {
                g_target = p.second;
				REQUIRE(s.guessNumber(p.first) == p.second);
		});
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
