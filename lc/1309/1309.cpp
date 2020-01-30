// 1309. Decrypt String from Alphabet to Integer Mapping
// Problem definition: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
// 2020-01-29

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
private:
    static constexpr int m_base{48};

public:
    std::string freqAlphabets(std::string s) {
        std::string output;
        for (size_t i{0}; i < s.length(); ++i) {
            char c;
            if (i + 2 < s.length() && s[i+2] == '#') {
                c = (s[i] == '1' ? 10 : 20) + s[i+1] + m_base;
                i += 2;
            } else {
                c = s[i] + m_base;
            }
            output.push_back(c);
        }
        return output;
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
