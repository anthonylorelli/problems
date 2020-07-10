// 0919. Complete Binary Tree Inserter
// Problem definition: https://leetcode.com/problems/complete-binary-tree-inserter/
// Accepted 2020-07-09

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <queue>

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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) : m_root{root} { 
        m_q.push(m_root);
        advance();
    }
    
    int insert(int v) {
        TreeNode* next {m_q.front()};
        int parent {next->val};
        TreeNode** node = next->left ? &next->right : &next->left;
        *node = new TreeNode{v};
        if (next->right) {
            m_q.push(next->left);
            m_q.push(next->right);
            m_q.pop();
        }
        return parent;
    }
    
    TreeNode* get_root() {
        return m_root;
    }

private:
    void advance() {
        TreeNode* node {m_q.front()};
        while (node->left && node->right) {
            m_q.push(node->left);
            m_q.push(node->right);
            m_q.pop();
            node = m_q.front();
        }        
    }

    TreeNode* m_root;
    std::queue<TreeNode*> m_q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

// TEST_CASE("LC test cases", "[Complete Binary Tree Inserter]") {
//     SECTION("Case 1") {
//         auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
//         Solution s;
//         REQUIRE(s.isCousins(tree, 3, 4) == false);
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
