// 0033. Search in Rotated Sorted Array
// Problem definition: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        return 0;      
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,int>> input {
        {{{4,5,6,7,0,1,2},0},4},
        {{{4,5,6,7,0,1,2},3},-1},
        {{{1},0},-1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                auto& [array, target] = testInput;
                REQUIRE(s.search(array, target) == expected);
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
