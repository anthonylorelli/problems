// 0107. Binary Tree Level Order Traversal II
// Problem definition: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Accepted 2020-06-01

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstdint>
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> results;
        if (!root) { return results; }
        std::queue<std::pair<TreeNode*,int>> levels;
        levels.push({root,0});
        while (!levels.empty()) {
            auto [node, depth] = levels.front();
            levels.pop();
            int nextDepth {depth + 1};
            if (nextDepth > results.size()) {
                results.push_back({node->val});
            } else {
                results[depth].push_back(node->val);
            }
            if (node->left) { levels.push({node->left, nextDepth}); }
            if (node->right) { levels.push({node->right, nextDepth}); }
        }
        std::reverse(results.begin(), results.end());
        return results;
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Binary Tree Level Order Traversal II]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{3, new TreeNode{9, nullptr, nullptr}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
        std::vector<std::vector<int>> result = {{15,7},{9,20},{3}};
        Solution s;
        REQUIRE(s.levelOrderBottom(tree) == result);
    }
    SECTION("Case 2") {
        auto tree = nullptr;
        std::vector<std::vector<int>> result = {};
        Solution s;
        REQUIRE(s.levelOrderBottom(tree) == result);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
