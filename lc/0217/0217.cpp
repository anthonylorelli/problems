// 0217. Contains Duplicate
// Problem definition: https://leetcode.com/problems/contains-duplicate/
// Accepted 2020-11-06
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        return std::unordered_set<int>{nums.begin(), nums.end()}.size() != nums.size();
    }

    bool containsDuplicate_find_if(std::vector<int>& nums) {
        std::unordered_set<int> set;
        return std::find_if(nums.begin(), nums.end(), [&set](const auto n){
            if (set.count(n)) { return true; }
            set.insert(n);
            return false;
        }) != nums.end();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,bool>> input {
        {{1,2,3,1}, true},
        {{1,2,3,4}, false},
        {{1,1,1,3,3,4,3,2,4,2},true},
        {{},false},
        {{1,1},true},
        {{2},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.containsDuplicate(testInput) == expected);
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
