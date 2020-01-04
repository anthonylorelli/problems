// 1003. Check If Word Is Valid After Substitutions
// Problem definition: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string S) {
        for (const auto c : S) {

        }

        return true;
    }
};

TEST_CASE("LC test cases", "[Check If Word Is Valid After Substitutions]") {
    std::vector<std::pair<std::string,bool>> input {
        {"aabcbc",true},{"abcabcababcc",true},{"abccba",false},{"cababc",false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.isValid(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
