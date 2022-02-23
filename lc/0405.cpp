// 0405. Convert a Number to Hexadecimal
// Problem definition: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Accepted 2019-11-27

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    char toChar(const short digit) const noexcept {
        switch (digit) {
            case 10: return 'a';
            case 11: return 'b';
            case 12: return 'c';
            case 13: return 'd';
            case 14: return 'e';
            case 15: return 'f';
            default: return digit + '0';
        }
    }

    std::string toHex(int num) {
        std::string s;
        unsigned int remainder = num;

        while (remainder > 0) {
            s = toChar(remainder & 0xf) + s;
            remainder >>= 4;
        }

        return s.length() > 0 ? s : "0";
    }
};

TEST_CASE("LC test cases", "[Convert a Number to Hexadecimal]") {
    Solution s;
    std::vector<std::pair<int,std::string>> input {
        {{26,"1a"},{-1,"ffffffff"},{0,"0"},{-89,"ffffffa7"}}
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
