// 0662. Maximum Width of Binary Tree
// Problem definition: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Accepted 2020-06-09

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

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
    int widthOfBinaryTree(TreeNode* root) {
        int max {0};
        if (!root) { return max; }
        std::queue<std::pair<TreeNode*,uint64_t>> queue;
        queue.push({root,1});
        while (!queue.empty()) {
            int width = queue.back().second - queue.front().second + 1;
            int length = queue.size();
            for (int n {0}; n < length; ++n) {
                auto [node, index] = queue.front();
                queue.pop();
                uint64_t next {index * 2};
                if (node->left) { queue.push({node->left, next}); }
                if (node->right) { queue.push({node->right, next + 1}); }
            }
            max = std::max(max, width);
        }
        return max;
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Maximum Width of Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        Solution s;
        REQUIRE(s.widthOfBinaryTree(tree) == 4);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
