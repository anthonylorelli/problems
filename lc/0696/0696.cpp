// 0696. Count Binary Substrings
// Problem definition: https://leetcode.com/problems/count-binary-substrings/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    int countBinarySubstrings(std::string s) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Count Binary Substrings]") {
    std::vector<std::pair<std::string,int>> input {
        {"00110011", 6}, {"10101", 4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countBinarySubstrings(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
