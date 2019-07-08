// 1080. Insufficient nodes in root to leaf path
// Problem definition: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Accepted ?

/* 
 */

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
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
        REQUIRE(true;
    }
}
