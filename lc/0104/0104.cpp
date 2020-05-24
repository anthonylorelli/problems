// 0104. Maximum Depth of Binary Tree
// Problem definition: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Accepted 2020-05-24

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } 

        int left {maxDepth(root->left)};
        int right {maxDepth(root->right)};

        return 1 + (left && right ? std::max(left, right) : 
            !left && !right ? 0 : left ? left : right);
    }
};

TEST_CASE("LC test cases", "[Maximum Depth of Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, nullptr, new TreeNode{2, new TreeNode{3}, nullptr}};
        int expected = 3;
        Solution s;
        REQUIRE(s.maxDepth(tree) == expected);
    }
    SECTION("Case 2") {
        auto tree = new TreeNode{1, new TreeNode{0, new TreeNode{0}, new TreeNode{0}}, 
            new TreeNode{0, new TreeNode{0}, new TreeNode{1}}};
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
