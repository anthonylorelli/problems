// 0979. Distribute Coins in Binary Tree
// Problem definition: https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Accepted 2020-07-05

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <queue>
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
    int distributeCoins(TreeNode* root) {
        auto [cost, moves] = evaluate(root);
        return moves;
    }

private:
    std::pair<int,int> evaluate(TreeNode* node) {
        if (!node) { return {0,0}; }
        
        auto [left_cost, left_moves] = evaluate(node->left);
        auto [right_cost, right_moves] = evaluate(node->right);

        int cost {node->val - 1 + left_cost + right_cost};
        return {cost, std::abs(cost) + left_moves + right_moves};
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Distribute Coins in Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
        Solution s;
        REQUIRE(s.distributeCoins(tree) == 0);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
