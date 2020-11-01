// 0112. Path Sum
// Problem definition: https://leetcode.com/problems/path-sum/
// Accepted 2020-10-31
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <array>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) { return false; }
        return pathSum(root, 0, sum);
    }

private:
    bool pathSum(const TreeNode* node, const int sum, const int target) {
        if (!node) { return false; }
        const int node_sum {sum + node->val};
        if (!node->left && !node->right) {
            return node_sum == target;
        }
        return pathSum(node->left, node_sum, target) || pathSum(node->right, node_sum, target);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::pair<std::string,int>,bool>> input {
        {{"[5,4,8,11,null,13,4,7,2,null,null,null,1]",22}, true},
        {{"[5,4,8,12,null,13,4,7,2,null,null,null,1]",22}, false},
        {{"[]",1}, false},
        {{"[]",0}, false},
        {{"[1]",1}, true},
        {{"[1,2]",1}, false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Codec c; 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.hasPathSum(c.deserialize(testInput.first), testInput.second) == expected);
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
