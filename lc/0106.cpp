// 0106. Construct Binary Tree from Inorder and Postorder Traversal
// Problem definition: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Accepted 2021-08-22
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>
#include <unordered_map>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (size_t i {0}; i < inorder.size(); ++i) {
            m_map[inorder[i]] = i;
        }
        m_post = postorder.rbegin();
        return make(0, inorder.size() - 1);
    }

    TreeNode* make(const int32_t start, const int32_t end) {
        if (start > end) {
            return nullptr;
        }

        auto root = new TreeNode{*m_post++};
        auto split = m_map[root->val];
        root->right = make(split + 1, end);
        root->left = make(start, split - 1);

        return root;
    }

private:
    std::unordered_map<int32_t,int32_t> m_map;
    std::vector<int>::reverse_iterator m_post;
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,bool>> input {
//         {{2,3,1,1,4},true},{{3,2,1,0,4},false},{{5},true},{{4,0},true},{{0,1},false},
//         {{1,1,1,1,0,1,1},false},{{0,1,1,1},false},{{2,1,2,0,1,2,0,1},true}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.canJump(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
