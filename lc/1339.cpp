// 1339. Maximum Product of Splitted Binary Tree
// Problem definition: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Accepted 2020-05-30

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstdint>
#include <iostream>

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

constexpr int64_t c_mod {1'000'000'000 + 7};

class Solution {
public:
    int maxProduct(TreeNode* root) {
        if (!root) { return 0; }
        const int64_t total {root->val + sumTree(root->left) + sumTree(root->right)};
        int64_t max {m_sums[0] * (total - m_sums[0])};
        std::for_each(m_sums.begin() + 1, m_sums.end(), [&](const int64_t n) { max = std::max(max, n * (total - n)); });
        return max % c_mod;
    }

private:
    int64_t sumTree(TreeNode* root) {
        if (!root) { return 0; }
        int64_t sum {root->val + sumTree(root->right) + sumTree(root->left)};
        m_sums.push_back(sum);
        return sum;
    }

    std::vector<int64_t> m_sums;
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Maximum Product of Splitted Binary Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{2, new TreeNode{4}, new TreeNode{5}}, new TreeNode{3, new TreeNode{6}, nullptr}};
        Solution s;
        REQUIRE(s.maxProduct(tree) == 110);
    }
    SECTION("Case 2") {
        auto tree = new TreeNode{1, nullptr, new TreeNode{2, new TreeNode{3}, new TreeNode{4, new TreeNode{5}, new TreeNode{6}}}};
        Solution s;
        REQUIRE(s.maxProduct(tree) == 90);
    }
    SECTION("Case 3") {
        auto tree = new TreeNode{1, new TreeNode{1}, nullptr};
        Solution s;
        REQUIRE(s.maxProduct(tree) == 1);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
