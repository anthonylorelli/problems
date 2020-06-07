// 0173. Binary Search Tree Iterator
// Problem definition: https://leetcode.com/problems/binary-search-tree-iterator/
// Accepted 2020-06-06

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <stack>
#include <iostream>

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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* current {m_stack.top()};
        m_stack.pop();
        traverse(current->right);
        return current->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }

private:
    void traverse(TreeNode* root) {
        while (root) {
            m_stack.push(root);
            root = root->left;
        }
    }

    std::stack<TreeNode*> m_stack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

// TEST_CASE("LC test cases", "[Binary Tree Zigzag Level Order Traversal]") {
//     SECTION("Case 1") {
//         auto tree = new TreeNode{3, new TreeNode{9, nullptr, nullptr}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
//         Solution s;
//         REQUIRE(s.isBalanced(tree) == false);
//     }
//     SECTION("Case 2") {
//         auto tree = nullptr;
//         Solution s;
//         REQUIRE(s.isBalanced(tree) == true);
//     }
//     SECTION("Case 3") {
//         auto tree = new TreeNode{1, new TreeNode{2, new TreeNode{4}, nullptr}, new TreeNode{3, nullptr, new TreeNode{5}}};
//         Solution s;
//         REQUIRE(s.isBalanced(tree) == false);
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
