// 0095. Unique Binary Search Trees II
// Problem definition: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>

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
    std::vector<TreeNode*> generateTrees(int n) {
        
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int,std::vector<std::vector<int>>>> input {
//         {{2,3,6,7},7,{{2,2,3},{7}}},
//         {{2,3,5},8,{{2,3,3},{2,2,2,2},{3,5}}},
//         {{2},1,{}},{{1},1,{{1}}},
//         {{1},2,{{1,1}}},{{3,5,8},11,{{3,8},{3,3,5}}},
//         {{2,7,6,3,5,1},9,{{2,7},{2,6,1},{2,3,1,1,1,1},{2,3,3,1},{2,5,1,1},
//             {2,1,1,1,1,1,1,1},{2,2,3,1,1},{2,2,5},{2,2,1,1,1,1,1},{2,2,2,3},
//             {2,2,2,1,1,1},{2,2,2,2,1},{7,1,1},{6,3},{6,1,1,1},{3,5,1},{3,1,1,1,1,1,1},
//             {3,3,1,1,1},{3,3,3},{5,1,1,1,1},{1,1,1,1,1,1,1,1,1}}}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, target, expected] = p;
//                 REQUIRE(s.combinationSum(testInput, target) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
