// 1530. Number of Good Leaf Nodes Pairs
// Problem definition: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

// Definition for a binary tree node.
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
    int countPairs(TreeNode* root, int distance) {
    }

private:
    void find_adjacent(TreeNode* node, const int index) {
        if (!node->left && !node->right) {
            m_leafs.push_back(index);
            return;
        }

        if (node->left) {
            add_adjacent(node->left, index);
        }

        if (node->right) {
            add_adjacent(node->right, index);
        }
    }

    void add_adjacent(TreeNode* node, const int index) {
        int next_index = m_adjacent.size();
        m_adjacent.push_back(std::vector<int>{});
        m_adjacent[index].push_back(next_index);
        m_adjacent[next_index].push_back(index);
        find_adjacent(node, next_index);
    }

    std::vector<int> m_leafs;
    std::vector<std::vector<int>> m_adjacent;
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

// TEST_CASE("LC test cases", "[Core]") {
//     SECTION("Case 1") {
//         std::string input {"abcabcbb"};
//         Solution s;
//         REQUIRE(s.lengthOfLongestSubstring(input) == 3);
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
