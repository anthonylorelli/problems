// 1339. Maximum Product of Splitted Binary Tree
// Problem definition: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Accepted ?

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

class iterator
{
public:
    iterator() = default;
    iterator(TreeNode* node) {
        traverse(node);
    }

    int operator*() {
        return m_stack.top()->val;
    }

    iterator& operator++() {
        TreeNode* node {m_stack.top()};
        m_stack.pop();
        traverse(node->right);
        traverse(node->left);
        return *this;
    }

    bool operator==(const iterator& i) const {
        return m_stack == i.m_stack;
    }

    bool operator!=(const iterator& i) const {
        return !(*this == i);
    }

private:
    std::stack<TreeNode*> m_stack;

    void traverse(TreeNode* node) {
        if (node) {
            m_stack.push(node);
        }
    }
};

class Solution {
public:
    int maxProduct(TreeNode* root) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Maximum Product of Splitted Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, nullptr, new TreeNode{2, new TreeNode{3}, nullptr}};
        std::vector<int> expected = {1, 2, 3};
        Solution s;
        REQUIRE(s.preorderTraversal(tree) == expected);
    }
    SECTION("Case 2") {
        auto tree = new TreeNode{4, 
            new TreeNode{3, new TreeNode{2}, new TreeNode{1}}, 
            new TreeNode{5, new TreeNode{6}, new TreeNode{7}}};
        std::vector<int> expected = {4, 3, 2, 1, 5, 6, 7};
        Solution s;
        REQUIRE(s.preorderTraversal(tree) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
