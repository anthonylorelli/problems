// 0102. Binary Tree Level Order Traversal
// Problem definition: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Accepted 2020-05-30

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) { return result; }
        std::queue<std::pair<TreeNode*,int>> nodes;
        nodes.push({root,0});
        while (!nodes.empty()) {
            auto [node, depth] = nodes.front();
            nodes.pop();
            if (depth + 1 > result.size()) {
                result.push_back({node->val});    
            } else {
                result[depth].push_back(node->val);
            }
            if (node->left) { nodes.push({node->left, depth + 1}); }
            if (node->right) { nodes.push({node->right, depth + 1}); }
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Binary Tree Level Order Traversal]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{3, new TreeNode{9, nullptr, nullptr}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
        std::vector<std::vector<int>> result = {{3},{9,20},{15,7}};
        Solution s;
        REQUIRE(s.levelOrder(tree) == result);
    }
    SECTION("Case 2") {
        auto tree = nullptr;
        std::vector<std::vector<int>> result = {};
        Solution s;
        REQUIRE(s.levelOrder(tree) == result);
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}
