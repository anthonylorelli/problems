// 0501. Find Mode in Binary Search Tree
// Problem definition: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Accepted 2020-06-13, 2020-09-27, 2020-09-28

#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/tree_iterator.h"
#include "../../inc/serialize.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <limits>

class Solution {
public:
    std::vector<int> findMode(TreeNode* root) {
        if (!root) { return {}; }
        m_previous = root->val;
        traverse(root, 0);
        return m_result;
    }

private:
    int traverse(const TreeNode* node, const int count) {
        if (!node) {
            return count;
        }

        int left_count {traverse(node->left, count)};

        left_count = m_previous != node->val ? 1 : left_count + 1;
        if (left_count > m_max) {
            m_result.clear();
            m_max = left_count;
        }
        if (left_count == m_max) {
            m_result.push_back(node->val);
        }
        m_previous = node->val;

        return traverse(node->right, left_count);
    }

    int m_max {1};
    std::vector<int> m_result;
    int m_previous {0};
};

class TwoPassTreeSolution {
public:
    std::vector<int> findMode(TreeNode* root) {
        if (!root) { return {}; }
        return collect_modes(root, find_max(root));
    }

private:
    template <typename Fn>
    int traverse(const TreeNode* node, const int count, Fn& handler) {
        if (!node) {
            return count;
        }

        int left_count {traverse(node->left, count, handler)};

        left_count = (left_count == 0 || m_previous != node->val) ? 1 : left_count + 1;
        handler(node->val, left_count);
        m_previous = node->val;

        return traverse(node->right, left_count, handler);
    }

    int find_max(const TreeNode* node) {
        int max {1};
        auto handler = [&max](const int, const int count) { max = std::max(max, count); };
        traverse(node, 0, handler);
        return max;
    }

    std::vector<int> collect_modes(TreeNode* node, const int target) {
        std::vector<int> result;
        auto handler = [&target, &result](const int value, const int count) { if (count == target) { result.push_back(value); }};
        traverse(node, 0, handler);
        return result;
    }

    int m_previous {0};
};

class IteratorSolution {
public:
    std::vector<int> findMode(TreeNode* root) {
        if (!root) { return {}; }
        return collect_modes(root, find_max(root));
    }

private:
    template <typename F>
    void group_elements(TreeNode* root, F fn) {
        tree_iterator begin {root};
        tree_iterator end {};
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

    std::vector<int> collect_modes(TreeNode* root, const int target) {
        std::vector<int> result;
        auto fn = [&result, &target](const int count, const int value) { if (count == target) { result.push_back(value); }};
        group_elements(root, fn);
        return result;
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
    Solution s;
    Codec c;
    SECTION("Case 1") {
        std::string input {"[1,null,2,2]"};
        std::vector<int> expected {2};
        REQUIRE(s.findMode(c.deserialize(input)) == expected);
    }
    SECTION("Case 2") {
        std::string input {"[6,2,8,0,4,7,9,null,null,2,6]"};
        std::vector<int> expected {2,6};
        REQUIRE(s.findMode(c.deserialize(input)) == expected);
    }
    SECTION("Case 3") {
        std::string input {"[]"};
        std::vector<int> expected {};
        REQUIRE(s.findMode(c.deserialize(input)) == expected);
    }
    SECTION("Case 4") {
        std::string input {"[4]"};
        std::vector<int> expected {4};
        REQUIRE(s.findMode(c.deserialize(input)) == expected);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
