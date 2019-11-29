// 0844. Backspace String Compare
// Problem definition: https://leetcode.com/problems/backspace-string-compare/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Convert a Number to Hexadecimal]") {
    Solution s;
    std::vector<std::pair<std::pair<std::string,std::string>,bool>> input {
        {{{"ab#c","ad#c"},true},{{"ab##","c#d#"},true},{{"a##c","#a#c"},true},{{"a#c",b},false}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.toHex(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
