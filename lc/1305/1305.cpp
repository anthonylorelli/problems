// 1305. All Elements in Two Binary Search Trees
// Problem definition: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <tuple>
#include <numeric>
#include <stack>
#include <iostream>

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class iterator
{
public:
    iterator() = default;
    iterator(TreeNode* node) {
        if (node) {
            m_stack.push(node);
            while (m_stack.top()->left) {
                m_stack.push(m_stack.top()->left);
            }
        }
    }

    int operator*() {
        if (m_stack.empty()) {
            throw std::exception("Empty stack");
        }
        return m_stack.top()->val;
    }

    iterator& operator++() {
        if (m_stack.empty()) {
            throw std::exception("Empty stack");
        }
        TreeNode* node {m_stack.top()};
        m_stack.pop();
        if (node->right) {
            m_stack.push(node->right);
            while (m_stack.top()->left) {
                m_stack.push(m_stack.top()->left);
            }
        }
        return *this;
    }

    bool operator==(const iterator& i) const {
        return (m_stack.empty() && i.m_stack.empty()) || (m_stack == i.m_stack);
    }

    bool operator!=(const iterator& i) const {
        return !(*this == i);
    }

private:
    std::stack<TreeNode*> m_stack;
};

template <typename Iterator, typename Output>
void copy(Iterator& it, Iterator& end, Output out) {
    while (it != end) {
        *out = *it;
        ++it;
        ++out;
    }
}

template <typename Iterator, typename Output>
void merge(Iterator& in1, Iterator& end1, Iterator& in2, Iterator& end2, Output out) {
    for ( ; in1 != end1; ++out) {
        if (in2 == end2) {
            ::copy(in1, end1, out);
            return;
        }
        if (*in2 < *in1) {
            *out = *in2;
            ++in2;
        } else {
            *out = *in1;
            ++in1;
        }
    }
    ::copy(in2, end2, out);
}

class Solution {
public:
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> result;
        ::iterator it1{root1}, it2{root2};
        ::iterator end;
        merge(it1, end, it2, end, std::back_inserter(result));
        return result;
    }
};

TEST_CASE("LC test cases", "[All Elements in Two Binary Search Trees]") {
    SECTION("LC test cases") {
        auto tree1 = new TreeNode{2, new TreeNode{1}, new TreeNode{4}};
        auto tree2 = new TreeNode{1, new TreeNode{0}, new TreeNode{3}};
        std::vector<int> expected = {0, 1, 1, 2, 3, 4};
        Solution s;
        REQUIRE(s.getAllElements(tree1, tree2) == expected);
    }
}

TEST_CASE("Basic test cases", "[All Elements in Two Binary Search Trees]") {
    SECTION("Test case 1") {
        auto tree = new TreeNode{2, new TreeNode{1}, new TreeNode{4}};
        std::vector<int> expected = {1, 2, 4};
        std::vector<int> actual;
        ::iterator it{tree};
        ::iterator end{};
        while (it != end) {
            actual.push_back(*it);
            ++it;
        }
        REQUIRE(expected == actual);
    }
    SECTION("Test case 2") {
        auto tree = new TreeNode{1, new TreeNode{0}, new TreeNode{3}};
        std::vector<int> expected = {0, 1, 3};
        std::vector<int> actual;
        ::iterator it{tree};
        ::iterator end{};
        while (it != end) {
            actual.push_back(*it);
            ++it;
        }
        REQUIRE(expected == actual);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
