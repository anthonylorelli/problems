// 1092. Shortest Common Supersequence
// Problem definition: https://leetcode.com/problems/shortest-common-supersequence/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    std::string shortestCommonSupersequence(std::string str1, std::string str2) {
        return "";        
    }
};

TEST_CASE("LC test cases", "[Repeated Substring Pattern]") {
    std::vector<std::pair<std::pair<std::string,std::string>,std::string>> input {
        {{"abac","cab"},"cabac"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.shortestCommonSupersequence(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
