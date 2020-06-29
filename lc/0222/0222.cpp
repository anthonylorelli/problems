// 0222. Count Complete Tree Nodes
// Problem definition: https://leetcode.com/problems/count-complete-tree-nodes/description/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
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

class Solution {
public:
    int countNodes(TreeNode* root) {
        return search(root, 1);
    }

private:
    int left_depth(TreeNode* root, const int current_depth) {
        return root ? left_depth(root->left, current_depth + 1) : current_depth;
    }

    int right_depth(TreeNode* root, const int current_depth) {
        return root ? right_depth(root->right, current_depth + 1) : current_depth;
    }

    int search(TreeNode* root, const int node_number) {
        if (!root) { return -1; }

        if (root->left && !root->right) {
            return node_number * 2;
        }

        if (!root->left && !root->right) {
            return node_number;
        }

        int left {search(root->left, node_number * 2)};
        int right {search(root->right, (node_number * 2) + 1)};

        return std::max(left, right);
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Count Complete Tree Nodes]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        Solution s;
        REQUIRE(s.countNodes(tree) == 0);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
