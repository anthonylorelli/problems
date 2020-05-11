// 0814. Binary Tree Pruning
// Problem definition: https://leetcode.com/problems/binary-tree-pruning/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <numeric>

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
    TreeNode* pruneTree(TreeNode* root) {
        if (root) {
            if (allZero(root->left)) {
                root->left = nullptr;
            }
            if (allZero(root->right)) {
                root->right = nullptr;
            }
        }
    }

private:
    bool allZero(TreeNode* root) {
        return root ? (root->val == 0 && allZero(root->right) && allZero(root->left)) : true;
    }
};

TEST_CASE("LC test cases", "[Binary Tree Pruning]") {
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
