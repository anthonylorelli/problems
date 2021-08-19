// 0081. Search in Rotated Sorted Array II
// Problem definition: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Accepted 2021-08-19
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <functional>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        auto pivot = std::adjacent_find(nums.begin(), nums.end(), std::greater<int>());
        return pivot == nums.end() ? binary_search(nums.begin(), nums.end(), target) :
            (binary_search(nums.begin(), pivot + 1, target) || binary_search(pivot + 1, nums.end(), target));
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int,bool>> input {
        {{2,5,6,0,0,1,2},0,true},{{2,5,6,0,0,1,2},3,false},
        {{1,2,3,4,5,6},5,true},{{1,2,3,4,5,5,6,6},7,false},
        {{1},0,false},{{1},2,false},{{5},5,true},{{1,0,1,1,1},0,true},
        {{2,2,3,2,2,2,2},3,true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, target, expected] = p;
                REQUIRE(s.search(testInput, target) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
