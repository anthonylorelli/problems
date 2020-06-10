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
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int count = queue.size();
            int width {0};
            int blanks {0};
            for (int n {0}; n < count; ++n) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current) {
                    width++;
                    queue.push(current->left);
                    queue.push(current->right);
                    if (blanks) {
                        width += blanks;
                        blanks = 0;
                    }
                } else if (width) {
                    blanks++;
                    queue.push(nullptr);
                    queue.push(nullptr);
                }
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
