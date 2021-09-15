// 0098. Validate Binary Search Tree
// Problem definition: https://leetcode.com/problems/validate-binary-search-tree/
// Accepted 2020-06-11

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <limits>

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());
    }

private:
    bool isValidBST(const TreeNode* root, const int64_t min, const int64_t max) const {
        if (!root) { return true; }
        if (root->val <= min || root->val >= max) { return false; }
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Validate Binary Search Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        Solution s;
        REQUIRE(s.isValidBST(tree) == false);
    }
    SECTION("Case 2") {
        auto tree = new TreeNode{2, new TreeNode{1}, new TreeNode{3}};
        Solution s;
        REQUIRE(s.isValidBST(tree) == true);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
