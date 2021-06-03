// 0009. Palindrome Number
// Problem definition: https://leetcode.com/problems/palindrome-number/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,bool>> input {
        {121,true},{-121,true},{10,false},{-101,false}
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
