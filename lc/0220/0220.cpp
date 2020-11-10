// 0219. Contains Duplicate III
// Problem definition: https://leetcode.com/problems/contains-duplicate-iii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        std::multimap<int,int> map;
        for (int i {0}; i < k; ++i) {
            const auto n {nums[i]};
            if (map.count(n)) {

            }
        }
        int min {map.begin()->first};
        int max {map.rbegin()->first};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::tuple<std::vector<int>,int,int>,bool>> input {
        {{{1,2,3,1},3,0}, true},
        {{{1,0,1,1},1,2}, true},
        {{{1,5,9,1,5,9},2,3},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                auto [input, k, t] = testInput;
                REQUIRE(s.containsNearbyAlmostDuplicate(input, k, t) == expected);
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
