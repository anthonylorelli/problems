// 0219. Contains Duplicate III
// Problem definition: https://leetcode.com/problems/contains-duplicate-iii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        if (nums.size() <= 1) { return false; }
        std::multiset<int> set;
        for (int i {1}; i <= k; ++i) {
            set.insert(nums[i]);
        }
        for (int i {0}, j {k+1}; i < nums.size(); ++i, ++j) {
            int next {nums[i]};
            auto target = set.lower_bound(next);
            int nearest = target != set.end() ? *target : *set.rbegin();
            if (std::abs(next - nearest) <= t) {
                return true;
            }
            if (i < (nums.size() - 1)) {
                set.erase(set.find(nums[i + 1]));
            }
            if (j < nums.size()) {
                set.insert(nums[j]);
            }
        }
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::tuple<std::vector<int>,int,int>,bool>> input {
        {{{1,2,3,1},3,0}, true},
        {{{1,0,1,1},1,2}, true},
        {{{1,5,9,1,5,9},2,3}, false},
        {{{},0,0}, false},
        {{{1},0,0}, false},
        {{{1,1},1,0}, true},
        {{{1,2},1,0}, false},
        {{{8,7,15,1,6,1,9,15},1,3}, true},
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
