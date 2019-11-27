// 0405. Convert a Number to Hexadecimal
// Problem definition: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    std::string toHex(int num) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Convert a Number to Hexadecimal]") {
    Solution s;
    std::vector<std::pair<int,std::string>> input {
        {{26,"1a"},{-1,"ffffffff"},{0,"0"}}
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
