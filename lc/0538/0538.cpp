// 0538. Convert BST to Greater Tree
// Problem definition: https://leetcode.com/problems/convert-bst-to-greater-tree/
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
        while (node) {
            m_stack.push(node);
            node = node->left;
        }
    }
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        return nullptr;        
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Convert BST to Greater Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        std::vector<int> expected;
        Solution s;
        REQUIRE(s.findMode(tree) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
