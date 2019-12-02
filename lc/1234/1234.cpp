// 1234. Replace the Substring for Balanced String
// Problem definition: https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>

class Solution {
public:
    int balancedString(std::string s) {
        int n {s.size() / 4};
        return 0;
    }
};

TEST_CASE("LC test cases", "[Replace the Substring for Balanced String]") {
    Solution s;
    std::vector<std::pair<std::string,int>> input {
        {{"QWER",0},{"QQWE",1},{"QQQW",2},{"QQQQ",3}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.isValid(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
