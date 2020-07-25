// 0783. Minimum Distance Between BST Nodes
// Problem definition: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Accepted 2020-07-25

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class tree_iterator
{
public:
    tree_iterator(TreeNode* node) {
        traverse(node);
    }

    int get() {
        return m_stack.top()->val;
    }

    void next() {
        TreeNode* node {m_stack.top()};
        m_stack.pop();
        traverse(node->right);
    }

    bool empty() {
        return m_stack.empty();
    }

private:
    void traverse(TreeNode* node) {
        while (node) {
            m_stack.push(node);
            node = node->left;
        }
    }

    std::stack<TreeNode*> m_stack;
};

class Solution {
public:
    Solution() : m_prev{std::numeric_limits<int>::min()},
        m_min{std::numeric_limits<int>::max()} {}

    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return m_min;
    }

    int minDiffInBSTIterative(TreeNode* root) {
        int min {std::numeric_limits<int>::max()};
        tree_iterator tree{root};
        int prev {tree.get()};
        tree.next();
        
        while (!tree.empty()) {
            int current {tree.get()};
            min = std::min(current - prev, min);
            prev = current;
            tree.next();
        }

        return min;
    }

private:
    void traverse(TreeNode* node) {
        if (!node) { return; }
        traverse(node->left);
        m_min = std::min(m_min, node->val - m_prev);
        m_prev = node->val;
        traverse(node->right);
    }

    int64_t m_prev;
    int64_t m_min;
};

//[90,69,null,49,89,null,52,null,null,null,null]
auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Minimum Distance Between BST Nodes]") {
    SECTION("Case 1") {
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
