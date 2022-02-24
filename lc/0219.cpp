// 0219. Contains Duplicate II
// Problem definition: https://leetcode.com/problems/contains-duplicate-ii/
// Accepted 2020-11-07
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i) {
            const auto n {nums[i]};
            if (map.count(n) && (i - map[n] <= k)) {
                return true;
            }
            map[n] = i;
        }
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,bool>> input {
        {{{1,2,3,1},3}, true},
        {{{1,0,1,1},1}, true},
        {{{1,2,3,1,2,3},2},false},
        {{{},0},false},
        {{{1},1},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.containsNearbyDuplicate(testInput.first, testInput.second) == expected);
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
