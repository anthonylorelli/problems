#pragma once

#include "treenode.h"
#include <stack>

class tree_iterator
{
public:
    tree_iterator() = default;
    tree_iterator(TreeNode* node) {
        traverse(node);
    }

    int operator*() {
        return m_stack.top()->val;
    }

    tree_iterator& operator++() {
        TreeNode* node {m_stack.top()};
        m_stack.pop();
        traverse(node->right);
        return *this;
    }

    bool operator==(const tree_iterator& i) const {
        return m_stack == i.m_stack;
    }

    bool operator!=(const tree_iterator& i) const {
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
