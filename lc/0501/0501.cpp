// 0501. Find Mode in Binary Search Tree
// Problem definition: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Accepted 2020-06-13

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <limits>

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

class iterator
{
public:
    iterator() = default;
    iterator(TreeNode* node) {
        traverse(node);
    }

    int operator*() {
        return m_stack.top()->val;
    }

    iterator& operator++() {
        TreeNode* node {m_stack.top()};
        m_stack.pop();
        traverse(node->right);
        return *this;
    }

    bool operator==(const iterator& i) const {
        return m_stack == i.m_stack;
    }

    bool operator!=(const iterator& i) const {
        return !(*this == i);
    }

private:
    std::stack<TreeNode*> m_stack;

    void traverse(TreeNode* node) {
        while (node) {
            m_stack.push(node);
            node = node->left;
        }
    }
};

class Solution {
public:
    std::vector<int> findMode(TreeNode* root) {
        std::vector<int> result;
        if (!root) { return result; }
        int max {find_max(root)};
        auto fn = [&result, &max](const int count, const int value) { if (count == max) { result.push_back(value); }};
        group_elements(root, fn);
        return result;
    }

private:
    template <typename F>
    void group_elements(TreeNode* root, F fn) {
        ::iterator begin {root};
        ::iterator end {};
        int prev {*begin};
        int count {1};
        ++begin;
        while (begin != end) {
            int current {*begin};
            if (current == prev) { 
                count++; 
            } else {
                fn(count, prev);
                count = 1;
                prev = current;
            }
            ++begin;
        }
        fn(count, prev);
    }

    int find_max(TreeNode* root) {
        int max {1};
        auto fn = [&max](const int count, const int) { max = std::max(max, count); };
        group_elements(root, fn);
        return max;
    }
};

auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Find Mode in Binary Search Tree]") {
    SECTION("Case 1") {
        auto tree = new TreeNode{1, new TreeNode{3, new TreeNode(5), new TreeNode(3)}, new TreeNode{2, nullptr, new TreeNode{9}}};
        std::vector<int> expected;
        Solution s;
        REQUIRE(s.findMode(tree) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
