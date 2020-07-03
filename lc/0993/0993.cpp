// 0993. Cousins in Binary Tree
// Problem definition: https://leetcode.com/problems/cousins-in-binary-tree/
// Accepted 2020-07-02

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <queue>

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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) { return false; }

        std::queue<TreeNode*> queue;
        queue.push(root);

        int x_parent {-1}, x_depth {-1};
        int y_parent {-1}, y_depth {-1};
        int current_depth {0};

        while (!queue.empty()) {
            int count = queue.size();
            for (int n {0}; n < count; ++n) {
                auto current = queue.front();
                queue.pop();

                if (current->left) {
                    queue.push(current->left);
                    if (current->left->val == x) {
                        x_parent = current->val;
                        x_depth = current_depth;
                    } else if (current->left->val == y) {
                        y_parent = current->val;
                        y_depth = current_depth;
                    }
                }

                if (current->right) {
                    queue.push(current->right);
                    if (current->right->val == x) {
                        x_parent = current->val;
                        x_depth = current_depth;
                    } else if (current->right->val == y) {
                        y_parent = current->val;
                        y_depth = current_depth;
                    }
                }
            }
            current_depth++;
        }
        if ((x_parent == y_parent) || x_parent == -1 || y_parent == -1 || x_depth != y_depth) {
            return false;
        }

        return true;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Cousins in Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
        Solution s;
        REQUIRE(s.isCousins(tree, 3, 4) == false);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
