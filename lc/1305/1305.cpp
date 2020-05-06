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

    bool operator==(const iterator& i) {
        return (m_stack.empty() && i.m_stack.empty()) || (m_stack == i.m_stack);
    }

    bool operator!=(const iterator& i) {
        return !(*this == i);
    }

private:
    std::stack<TreeNode*> m_stack;
};

class Solution {
public:
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> result;
        iterator i1 {root1}, i2 {root2};
        iterator end;
        std::merge(i1, end, i2, end, std::back_inserter(result));
        return result;
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
