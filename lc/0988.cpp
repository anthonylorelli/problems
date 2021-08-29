// 0988. Smallest String Starting From Leaf
// Problem definition: https://leetcode.com/problems/smallest-string-starting-from-leaf/
// Accepted 2020-07-15

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <set>

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
    std::string smallestFromLeaf(TreeNode* root) {
        constexpr int size {8501};
        char buffer[size];
        buffer[size-1] = '\0';
        if (root) {
            walk(root, buffer, size - 2);
        }
        return m_set.size() > 0 ? *m_set.begin() : "";
    }

private:
    void walk(TreeNode* node, char* buffer, const int index) {
        buffer[index] = node->val + 'a';
        if (!node->left && !node->right) {
            m_set.insert(std::string{buffer + index});
            return;
        }
        const int next {index - 1};
        if (node->left) {
            walk(node->left, buffer, next);
        }
        if (node->right) {
            walk(node->right, buffer, next);
        }
    }

    std::set<std::string> m_set;
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

// TEST_CASE("LC test cases", "[Complete Binary Tree Inserter]") {
//     SECTION("Case 1") {
//         auto tree = new TreeNode{1, new TreeNode{2, new TreeNode(4), new TreeNode(5)}, new TreeNode{3, new TreeNode{6}, nullptr}};
//         Solution s;
//         REQUIRE(s.isCousins(tree, 3, 4) == false);
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
