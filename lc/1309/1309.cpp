// 1309. Decrypt String from Alphabet to Integer Mapping
// Problem definition: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    std::string freqAlphabets(std::string s) {
        
    }
};

TEST_CASE("LC test cases", "[Decrypt String from Alphabet to Integer Mapping]") {
    std::vector<std::pair<std::string,std::string>> input {
        {"10#11#12","jkab"},{"1326#","acz"},{"25#","y"},
        {"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#","abcdefghijklmnopqrstuvwxyz"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.freqAlphabets(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
