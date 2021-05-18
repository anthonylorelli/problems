// 0513. Find Bottom Left Tree Value
// Problem definition: https://leetcode.com/problems/find-bottom-left-tree-value/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <queue>

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
    int findBottomLeftValue(TreeNode* root) {
        int left_most = root->val;
        std::queue<std::pair<int32_t,bool>> q;
        while (!q.empty()) {
            auto s = q.size();
            for (size_t i {0}; i < s; ++i) {
                
            }
        }
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int>> input {
//         {{1,1,1},1},{{1,2,2,2,5,0},3},{{3,2,1},0}
//     };

//     SECTION("Test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&](auto& p) {
//                 auto& [testInput, expected] = p;
//                 REQUIRE(Solution{}.waysToSplit(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
