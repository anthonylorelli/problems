// 0637. Average of Levels in Binary Tree
// Problem definition: https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Accepted 2020-06-06

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
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> result;
        if (!root) { return result; }
        std::queue<std::pair<TreeNode*,int>> queue;
        queue.push({root,0});
        std::vector<int> counts;
        while (!queue.empty()) {
            auto [node, depth] = queue.front();
            queue.pop();
            int nextDepth {depth + 1};
            if (nextDepth > result.size()) {
                result.push_back(node->val);
                counts.push_back(1);
            } else {
                result[depth] += node->val;
                counts[depth]++;
            }
            if (node->left) { queue.push({node->left, nextDepth}); }
            if (node->right) { queue.push({node->right, nextDepth}); }
        }
        std::transform(result.begin(), result.end(), counts.begin(), result.begin(), 
            [](const auto val, const auto count) { return val / count; });
        return result;
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Average of Levels in Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{3, new TreeNode{9, nullptr, nullptr}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
        std::vector<double> expected = {3, 14.5, 11};
        Solution s;
        REQUIRE(s.averageOfLevels(tree) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
