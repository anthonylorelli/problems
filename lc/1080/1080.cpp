// 1080. Insufficient nodes in root to leaf path
// Problem definition: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Accepted 2019-07-11

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int x) : val{x}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    const bool pruneTree(TreeNode* root, const int limit, const int sum) const {
        if (!root->left && !root->right) {
            return (root->val + sum) < limit;
        } else {
            const bool pruneLeft { root->left ? pruneTree(root->left, limit, root->val + sum) : true };
            const bool pruneRight { root->right ? pruneTree(root->right, limit, root->val + sum) : true };

            if (pruneLeft) { root->left = nullptr; }
            if (pruneRight) { root->right = nullptr; }

            return (pruneLeft && pruneRight) ? true : false;
        }
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        const bool pruneRoot {pruneTree(root, limit, 0)};
        return pruneRoot ? nullptr : root;
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
