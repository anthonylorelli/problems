// 0437. Path Sum III
// Problem definition: https://leetcode.com/problems/path-sum-iii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        return 0;
    }

private:
    int pathSum(const TreeNode* node, std::unordered_multiset<int> set, const int target) {
        if (!node) { return 0; }
        int count {0};
        if (set.count(target - node->val)) {
            count++;
        }
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::pair<std::string,int>,int>> input {
        {{"[10,5,-3,3,2,null,11,3,-2,null,1]",8}, 7}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Codec c; 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.pathSum(c.deserialize(testInput.first), testInput.second) == expected);
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
