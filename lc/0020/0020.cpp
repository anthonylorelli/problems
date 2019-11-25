// 0020. Valid Parentheses
// Problem definition: https://leetcode.com/problems/valid-parentheses/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Minimum Add to Make Parentheses Valid]") {
    Solution s;
    std::vector<std::pair<std::string,bool>> input {
        {{"()",true},{"()[]{}",true},{"(]",false},{"([)]",false},{"{[]}",true}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.isValid(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
