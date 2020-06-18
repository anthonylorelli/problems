// 0114. Flatten Binary Tree to Linked List
// Problem definition: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <limits>

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
    void flatten(TreeNode* root) {
        merge(root);
        return root;
    }

private:
    TreeNode* merge(TreeNode* root) {
        if (!root) { return nullptr; }

        auto left {merge(root->left)};
        auto right {merge(root->right)};

        if (!left && !right) { return root; }
        if (!left) { return right; }
        if (!right) { 
            std::swap(root->right, root->left);
            return left; 
        }

        left->right = root->right;
        root->left = nullptr;
        return right;
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Flatten Binary Tree to Linked List]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        std::vector<int> expected;
        Solution s;
        REQUIRE_NOTHROW(s.flatten(tree));
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
