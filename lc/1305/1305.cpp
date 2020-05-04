// 1305. All Elements in Two Binary Search Trees
// Problem definition: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <numeric>

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
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        return {};
    }
};

TEST_CASE("LC test cases", "[All Elements in Two Binary Search Trees]") {
    // std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
    //     {{{1,1},{3,4},{-1,0}},7},{{{3,2},{-2,2}},5},
    //     {{{1,1}},0}
    // };

    // SECTION("LC test cases") {
    //     std::for_each(std::begin(input), std::end(input),
    //         [&input](auto& p) { 
    //             Solution s;
    //             auto& [testInput, expected] = p;
    //             REQUIRE(s.minTimeToVisitAllPoints(testInput) == expected);
    //         });
    // }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
