// 0094. Binary Tree Inorder Traversal
// Problem definition: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Accepted 2020-05-18

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <stack>
#include <tuple>

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
        //return (m_stack.empty() && i.m_stack.empty()) || (m_stack == i.m_stack);
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
            while (m_stack.top()->left) {
                m_stack.push(m_stack.top()->left);
            }
        }
    }
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        ::iterator it {root}, end{};
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
        std::vector<int> expected = {1, 3, 2};
        Solution s;
        REQUIRE(s.inorderTraversal(tree) == expected);
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
