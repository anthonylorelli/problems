// 0022. Generate Parentheses
// Problem definition: https://leetcode.com/problems/generate-parentheses/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Generate Parentheses]") {
    std::vector<std::pair<int,std::vector<std::string>>> input {
        {3,{"((()))", "(()())","(())()","()(())","()()()"}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.generateParenthesis(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
