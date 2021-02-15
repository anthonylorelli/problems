// 0421. Maximum XOR of Two Numbers in an Array
// Problem definition: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{3,10,5,25,2,8},28},
        {{0},0},
        {{2,4},6},
        {{8,10,2},10},
        {{14,70,53,83,49,91,36,80,92,51,66,70},127}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findMaximumXOR(testInput) == expected);
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
