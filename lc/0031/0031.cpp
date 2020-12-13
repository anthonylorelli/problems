// 0031. Next Permutation
// Problem definition: https://leetcode.com/problems/next-permutation/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{1,2,3},{1,3,2}},
        {{3,2,1},{1,2,3}},
        {{1,1,5},{1,5,1}},
        {{1},{1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                s.nextPermutation(testInput);
                REQUIRE(testInput == expected);
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
