// 0235. Lowest Common Ancestor of a Binary Search Tree
// Problem definition: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return nullptr;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<uint32_t,uint32_t>> input {
//         {0b00000010100101000001111010011100,0b00111001011110000010100101000000},
//         {0b11111111111111111111111111111101,0b10111111111111111111111111111111}
//     };

//     SECTION("Test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&](auto& p) {
//                 auto& [testInput, expected] = p;
//                 REQUIRE(Solution{}.reverseBits(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
