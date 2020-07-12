// 0108. Convert Sorted Array to Binary Search Tree
// Problem definition: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Accepted 2020-07-11

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return create(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* create(const std::vector<int>& nums, const int low, const int high) const {
        if (low > high) { return nullptr; }

        const int middle {(low + high) / 2};
        TreeNode* next = new TreeNode{nums[middle]};
        next->left = create(nums, low, middle - 1);
        next->right = create(nums, middle + 1, high);
        return next;
    }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Convert Sorted Array to Binary Search Tree]") {
    SECTION("Case 1") {
        std::vector<int> input = {-10,-3,0,5,9};
        Solution s;
        REQUIRE(s.sortedArrayToBST(input) == nullptr);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
