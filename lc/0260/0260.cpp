// 0260. Single Number III
// Problem definition: https://leetcode.com/problems/single-number-iii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{1,2,1,3,2,5},{3,5}},
        {{-1,0},{-1,0}},
        {{0,1},{0,1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.singleNumber(testInput) == expected);
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
