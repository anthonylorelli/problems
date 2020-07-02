// 0993. Cousins in Binary Tree
// Problem definition: https://leetcode.com/problems/cousins-in-binary-tree/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
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

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto [x_parent, x_depth] = find(root, -1, x, 0);
        auto [y_parent, y_depth] = find(root, -1, y, 0);

        if (x_parent == -1 || y_parent == -1) {
            return false;
        }

        if (x_parent == y_parent || x_depth != y_depth) {
            return false;
        }

        return true;
    }

private:
    std::pair<int,int> find(const TreeNode* node, const int parent, const int n, const int depth) {
        if (!node) { return {-1,-1}; }

        if (node->val == n) {
            return {parent,depth};
        }

        if (n < node->val) {
            return find(node->left, node->val, n, depth + 1);
        }

        return find(node->right, node->val, n, depth + 1);
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Cousins in Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
        Solution s;
        REQUIRE(s.isCousins(tree, 3, 4) == false);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
