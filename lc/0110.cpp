// 0110. Balanced Binary Tree
// Problem definition: https://leetcode.com/problems/balanced-binary-tree/
// Accepted 2020-06-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return compareHeight(root) != -1;
    }

private:
    int compareHeight(const TreeNode* root) {
        if (!root) { return 0; }
        const auto left = compareHeight(root->left);
        if (left == -1) { return left; }
        const auto right = compareHeight(root->right);
        if (right == -1) { return right; }
        if (std::abs(left - right) > 1) { return -1; }
        return std::max(left, right) + 1;
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Binary Tree Zigzag Level Order Traversal]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{3, new TreeNode{9, nullptr, nullptr}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
        Solution s;
        REQUIRE(s.isBalanced(tree) == false);
    }
    SECTION("Case 2") {
        auto tree = nullptr;
        Solution s;
        REQUIRE(s.isBalanced(tree) == true);
    }
    SECTION("Case 3") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode{4}, nullptr}, new TreeNode{3, nullptr, new TreeNode{5}}};
        Solution s;
        REQUIRE(s.isBalanced(tree) == false);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
