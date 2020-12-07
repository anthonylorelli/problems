// 0227. Basic Calculator II
// Problem definition: https://leetcode.com/problems/basic-calculator-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>

class Solution {
public:
    int calculate(std::string s) {
        return 0;        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,int>> input {
        {"3+2*2", 7},
        {"3/2", 1},
        {"3+5 / 2", 5}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.calculate(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
