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
    const bool setSubset(TreeNode* root, const int limit, const int sum) const {
        if (!root->left && !root->right) {
            return !((root->val + sum) < limit);
        } else {
            const bool leftState { root->left ? setSubset(root->left, limit, root->val + sum) : false };
            const bool rightState { root->right ? setSubset(root->right, limit, root->val + sum) : false };

            if (!leftState) { root->left = nullptr; }
            if (!rightState) { root->right = nullptr; }

            return (!leftState && !rightState) ? false : true;
        }
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        const bool state{setSubset(root, limit, root->val)};
        return !state ? nullptr : root;
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

//Limit 22
//Output:   [5,4,8,11,null,17,4,7,1,null,null,5,3]
//Expected: [5,4,8,11,null,17,4,7,null,null,null,5]