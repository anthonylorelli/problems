// 0145. Binary Tree Postorder Traversal
// Problem definition: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

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
    std::vector<int> postorderTraversal(TreeNode* root) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Binary Tree Postorder Traversal]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, nullptr, new TreeNode{0, new TreeNode{0}, new TreeNode{1}}};
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
