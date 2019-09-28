// 0005. Longest Palindromic Substring
// Problem definition: https://leetcode.com/problems/longest-palindromic-substring/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        for (int i = 0; i < s.length(); ++i) {
            
        }
        return "";
    }
};

TEST_CASE("LC test cases", "[Longest Palindromic Substring]") {
    Solution s;
    std::vector<std::pair<std::string,std::string>> input {
        {"",""}, {"babad","bab"}, {"cbbd","bb"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.longestPalindrome(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
