// 0965. Univalued Binary Tree
// Problem definition: https://leetcode.com/problems/univalued-binary-tree/
// Accepted 2020-05-13

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

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
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);
    }

private:
    bool isUnivalTree(TreeNode* root, int val) {
        return root ? (root->val == val && isUnivalTree(root->left, val) && isUnivalTree(root->right, val)) : true;
    }
};

TEST_CASE("LC test cases", "[Univalued Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, nullptr, new TreeNode{0, new TreeNode{0}, new TreeNode{1}}};
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
