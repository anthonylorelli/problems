// 0230. Kth Smallest Element in a BST
// Problem definition: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Accepted 2020-06-30

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        traverse(root, stack);
        while (true) {
            TreeNode* current = stack.top();
            stack.pop();
            if (--k == 0) {
                return current->val;
            }
            traverse(current->right, stack);
        }
        return 0;
    }

private:
    void traverse(TreeNode* node, std::stack<TreeNode*>& stack) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Kth Smallest Element in a BST]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
        Solution s;
        REQUIRE(s.kthSmallest(tree, 3) == 6);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
