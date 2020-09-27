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
    template <typename Fn>
    int traverse(const TreeNode* node, const int count, Fn& handler) {
        if (!node) {
            return count;
        }

        int left_count {traverse(node->left, count, handler)};

        if (left_count == 0) {
            left_count = 1;
            m_previous = node->val;
        } else if (m_previous == node->val) {
            left_count++;
        } else {
            handler(m_previous, left_count);
            left_count = 1;
            m_previous = node->val;
        }

        std::cout << "Node: " << node->val << " Count: " << left_count << "\n";

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
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
