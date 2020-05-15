// 0145. Binary Tree Postorder Traversal
// Problem definition: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
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

class iterator
{
public:
    iterator() = default;
    iterator(TreeNode* node) : m_last{nullptr} {
        seek(node);
    }

    int operator*() {
        return m_stack.top()->val;
    }

    iterator& operator++() {
        TreeNode* node {m_stack.top()};
        if (m_last == node) {
            m_stack.pop();
        } 
        if (!m_stack.empty()) {
            seek(m_stack.top()->right);
        }
        return *this;
    }

    bool operator==(const iterator& i) const {
        return (m_stack.empty() && i.m_stack.empty()) || (m_stack == i.m_stack);
    }

    bool operator!=(const iterator& i) const {
        return !(*this == i);
    }

private:
    std::stack<TreeNode*> m_stack;
    TreeNode* m_last {nullptr};

    void seek(TreeNode* node) {
        while (node) {
            m_stack.push(node);
            node = node->left ? node->left : node->right;
        }
        m_last = m_stack.top();
    }
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        ::iterator it {root}, end {};
        while (it != end) {
            result.push_back(*it);
            ++it;
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Binary Tree Postorder Traversal]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, nullptr, new TreeNode{2, new TreeNode{3}, nullptr}};
        std::vector<int> expected = {3, 2, 1};
        Solution s;
        REQUIRE(s.postorderTraversal(tree) == expected);
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
