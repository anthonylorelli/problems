// 0009. Palindrome Number
// Problem definition: https://leetcode.com/problems/palindrome-number/
// Accepted 2021-06-04
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <stack>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int32_t reversed {0};
        while (x > reversed) {
            reversed = (reversed * 10) + (x % 10);
            x /= 10;
        }
        return x == reversed || x == reversed / 10;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,bool>> input {
        {121,true},{-121,false},{10,false},{-101,false},
        {1,true},{12344321,true}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.isPalindrome(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
