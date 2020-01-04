// 0459. Repeated Substring Pattern
// Problem definition: https://leetcode.com/problems/repeated-substring-pattern/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Repeated Substring Pattern]") {
    std::vector<std::pair<std::string,bool>> input {
        {"abab",true},{"aba",false},{"abcabcabcabc",true},{"aaa",true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.isValid(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
