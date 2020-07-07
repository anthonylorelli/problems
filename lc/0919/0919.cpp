// 0919. Complete Binary Tree Inserter
// Problem definition: https://leetcode.com/problems/complete-binary-tree-inserter/
// Accepted ?

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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        
    }
    
    int insert(int v) {
        
    }
    
    TreeNode* get_root() {
        
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

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
