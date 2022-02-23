// 0665. Find Largest Value in Each Tree Row
// Problem definition: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Accepted 2020-07-22

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Definition for a binary tree node.
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
    std::vector<int> largestValues(TreeNode* root) {
        if (!root) { return {}; }
        std::vector<int> results;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int max {std::numeric_limits<int>::min()};
            int size = queue.size();
            for (int n {0}; n < size; ++n) {
                TreeNode* node {queue.front()};
                queue.pop();
                max = std::max(max, node->val);
                if (node->left) { queue.push(node->left); }
                if (node->right) { queue.push(node->right); }
            }
            results.push_back(max);
        }
        return results;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Find Largest Value in Each Tree Row]") {
    SECTION("Case 1") {
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
