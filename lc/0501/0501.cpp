// 0501. Find Mode in Binary Search Tree
// Problem definition: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Accepted 2020-06-13

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
        return collect_modes(root, find_max(root));
    }

private:
    int find_max(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int max {find_max(node->left)};

        if (m_first) {
            m_first = false;
            m_current = node->val;
            max = 1;
        } else {
            m_previous = m_current;
            m_current = node->val;
            if (m_current == m_previous) {
                max++;
            }
        }
    }

    std::vector<int> collect_modes(TreeNode* node, const int max) {
        std::vector<int> result;
        return result;
    }

    bool m_first {true};
    int m_current {0};
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
