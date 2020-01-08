// 0459. Repeated Substring Pattern
// Problem definition: https://leetcode.com/problems/repeated-substring-pattern/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <string_view>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        const auto max {s.length() / 2};
        const char* str {s.c_str()};
        for (size_t i {1}; i <= max; ++i) {
            if (s.length() % i) { continue; }
            std::string_view sv {str, i};
            for (size_t start {i}; start < s.length(); start += i) {
                std::string_view next {str + start, i};
                if (sv != next) { continue; }
            }
            return true;
        }

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
                REQUIRE(s.repeatedSubstringPattern(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
