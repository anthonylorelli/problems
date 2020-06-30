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
        return root ? search(root, 1) : 0;
    }

private:
    int left_depth(TreeNode* root, const int current_depth) {
        return root ? left_depth(root->left, current_depth + 1) : current_depth;
    }

    int right_depth(TreeNode* root, const int current_depth) {
        return root ? right_depth(root->right, current_depth + 1) : current_depth;
    }

    int search(TreeNode* root, const int node_number) {
        if (!root->left && !root->right) { return node_number; }

        int left_min {left_depth(root->left, 0)};
        int left_max {right_depth(root->left, 0)};

        if (left_min != left_max) {
            return search(root->left, node_number * 2);
        }

        int right_min {left_depth(root->right, 0)};
        int right_max {right_depth(root->right, 0)};

        if (right_min != right_max) {
            return search(root->right, node_number * 2 + 1);
        }

        if (left_max != right_min) {
            return search(root->left, node_number * 2);
        }

        return search(root->right, node_number * 2 + 1);
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
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
        Solution s;
        REQUIRE(s.countNodes(tree) == 6);
    }
    SECTION("Case 2") {
        auto tree = nullptr;
        Solution s;
        REQUIRE(s.countNodes(tree) == 0);
    }
    SECTION("Case 3") {
        auto tree = new TreeNode{1};
        Solution s;
        REQUIRE(s.countNodes(tree) == 1);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
