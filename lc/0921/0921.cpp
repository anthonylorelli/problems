// 0921. Minimum Add to Make Parentheses Valid
// Problem definition: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Accepted 2019-11-23

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    int minAddToMakeValid(std::string S) {
        int left {0}, total {0};
        for (const auto c : S) {
            if (c == '(') {
                left++;
            } else if (left) { 
                left--; 
            } else { 
                total++; 
            }
        }

        return total + left;
    }
};

TEST_CASE("LC test cases", "[Minimum Add to Make Parentheses Valid]") {
    Solution s;
    std::vector<std::pair<std::string,int>> input {
        {{"())",1},{"(((",3},{"()",0},{"()))((",4},{"",0},{"(",1},{")",1},{"(()())((",2}}
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
