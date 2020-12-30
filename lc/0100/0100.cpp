// 0100. Same Tree
// Problem definition: https://leetcode.com/problems/same-tree/
// Accepted 2020-12-29
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) { return true; }
        if (!p || !q) { return false; }
        if (p->val != q->val) { return false; }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::pair<std::pair<std::vector<int>,int>,int>> input {
//         {{{4,5,6,7,0,1,2},0},4},
//         {{{4,5,6,7,0,1,2},3},-1},
//         {{{1},0},-1},
//         {{{1},1},0},
//         {{{1,0},0},1},
//         {{{1,0},1},0},
//         {{{1,3},0},-1}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 auto& [array, target] = testInput;
//                 REQUIRE(s.search(array, target) == expected);
//             });
//     }
// }

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
