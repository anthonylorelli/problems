// 0921. Minimum Add to Make Parentheses Valid
// Problem definition: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    int minAddToMakeValid(std::string S) {
        
    }
};

TEST_CASE("LC test cases", "[Guess Number Higher or Lower II]") {
    Solution s;
    std::vector<std::pair<std::string,int>> input {
        {{"())",1},{"(((",3},{"()",0},{"()))((",4}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.minAddToMakeValid(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
