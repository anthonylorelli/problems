// 0219. Contains Duplicate III
// Problem definition: https://leetcode.com/problems/contains-duplicate-iii/
// Accepted 2020-11-11
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        if (nums.size() <= 1) { return false; }
        std::multiset<int> set;
        for (int i {0}; i < nums.size(); ++i) {
            auto nearest = set.lower_bound(nums[i]);
            if (nearest != set.end() && is_nearby(*nearest, nums[i], t)) {
                return true;
            }
            if (nearest != set.begin() && is_nearby(nums[i], *std::prev(nearest), t)) {
                return true;
            }
            set.insert(nums[i]);
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }

private:
    bool is_nearby(const int64_t lhs, const int64_t rhs, const int64_t t) const {
        return lhs <= (rhs + t);
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
