// 0137. Single Number II
// Problem definition: https://leetcode.com/problems/single-number-ii/
// Accepted 2020-11-23
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int seen_once {0}, seen_twice {0};
        for (const int n : nums) {
            seen_once = (seen_once^n) & ~seen_twice;
            seen_twice = (seen_twice^n) & ~seen_once;
        }
        return seen_once;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2,2,3,2},3},
        {{0,1,0,1,0,1,99},99}
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
