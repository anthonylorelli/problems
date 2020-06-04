// 0103. Binary Tree Zigzag Level Order Traversal
// Problem definition: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Accepted 2020-06-03

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> results;
        if (!root) { return results; }
        std::queue<std::pair<TreeNode*,int>> queue;
        std::deque<int> values;
        int current {0};
        queue.push({root,current});
        while (!queue.empty()) {
            auto [node, depth] = queue.front();
            queue.pop();
            int nextDepth {depth + 1};

            if (current != depth) {
                results.emplace_back();
                std::copy(values.begin(), values.end(), std::back_inserter(results[current]));
                current = depth;
                values.clear();
            } 

            if (depth % 2) {
                values.push_front(node->val);
            } else {
                values.push_back(node->val);
            }

            if (node->left) { queue.push({node->left, nextDepth}); }
            if (node->right) { queue.push({node->right, nextDepth}); }
        }

        results.emplace_back();
        std::copy(values.begin(), values.end(), std::back_inserter(results[results.size() - 1]));

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

TEST_CASE("LC test cases", "[Binary Tree Zigzag Level Order Traversal]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{3, new TreeNode{9, nullptr, nullptr}, new TreeNode{20, new TreeNode{15}, new TreeNode{7}}};
        std::vector<std::vector<int>> result = {{3},{20,9},{15,7}};
        Solution s;
        REQUIRE(s.zigzagLevelOrder(tree) == result);
    }
    SECTION("Case 2") {
        auto tree = nullptr;
        std::vector<std::vector<int>> result = {};
        Solution s;
        REQUIRE(s.zigzagLevelOrder(tree) == result);
    }
    SECTION("Case 3") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode{4}, nullptr}, new TreeNode{3, nullptr, new TreeNode{5}}};
        std::vector<std::vector<int>> result = {{1},{3,2},{4,5}};
        Solution s;
        REQUIRE(s.zigzagLevelOrder(tree) == result);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
