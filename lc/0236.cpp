// 0236. Lowest Common Ancestor of a Binary Tree
// Problem definition: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return nullptr;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<int,int,std::vector<std::vector<int>>>> input {
//         {3,7,{{1,2,4}}},{3,9,{{1,2,6},{1,3,5},{2,3,4}}},{4,1,{}},
//         {3,2,{}},{9,45,{{1,2,3,4,5,6,7,8,9}}}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [k, n, expected] = p;
//                 REQUIRE(s.combinationSum3(k,n) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
