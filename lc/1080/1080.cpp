// 1080. Insufficient nodes in root to leaf path
// Problem definition: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Accepted ?

/* 
 */

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <initializer_list>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int x) : val{x}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    int setSubset(TreeNode* root, const int limit, const int sum) {
        const int leftSum { root->left ? setSubset(root->left, limit, root->val + sum) : 0 };
        const int rightSum { root->right ? setSubset(root->right, limit, root->val + sum) : 0 };
        if (leftSum < limit) { root->left = nullptr; }
        if (rightSum < limit) { root->right = nullptr; }
        return root->val + leftSum + rightSum;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        const int sum{setSubset(root, limit, root->val)};
        return sum < limit ? nullptr : root;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("", "[Insufficient nodes]") {
    SECTION("") {
        Solution s;
        REQUIRE(true);
    }
}
