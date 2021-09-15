// 0003. Longest Substring Without Repeating Characters
// Problem definition: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Accepted 2020-08-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> counts(256,0);
        auto left {s.begin()}, right {s.begin()};
        auto max {std::distance(left, right)};
        while (right != s.end()) {
            counts[*right]++;
            while (counts[*right] > 1) {
                counts[*left]--;
                ++left;
            }
            ++right;
            max = std::max(max, std::distance(left, right));
        }
        max = std::max(max, std::distance(left, right));
        return max;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Core]") {
    SECTION("Case 1") {
        std::string input {"abcabcbb"};
        Solution s;
        REQUIRE(s.lengthOfLongestSubstring(input) == 3);
    }
    SECTION("Case 2") {
        std::string input {"bbbbb"};
        Solution s;
        REQUIRE(s.lengthOfLongestSubstring(input) == 1);
    }
    SECTION("Case 3") {
        std::string input {"pwwkew"};
        Solution s;
        REQUIRE(s.lengthOfLongestSubstring(input) == 3);
    }
    SECTION("Case 4") {
        std::string input {"abcdef"};
        Solution s;
        REQUIRE(s.lengthOfLongestSubstring(input) == 6);
    }
    SECTION("Case 5") {
        std::string input {""};
        Solution s;
        REQUIRE(s.lengthOfLongestSubstring(input) == 0);
    }
    SECTION("Case 6") {
        std::string input {"a"};
        Solution s;
        REQUIRE(s.lengthOfLongestSubstring(input) == 1);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
