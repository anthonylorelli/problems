// 0508. Symmetric Tree
// Problem definition: https://leetcode.com/problems/symmetric-tree/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) { return true; }
        return is_mirror(root->left, root->right);
    }

private:
    bool is_mirror(const TreeNode* a, const TreeNode* b) {
        if (!a && !b) { return true; }
        if (!a || !b) { return false; }
        return a->val == b->val && is_mirror(a->left, b->right) &&
            is_mirror(a->right, b->left);
    }
};

class OverlyComplicatedIterativeSolution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        std::deque<int> d;
        d.push_back(root->val);

        while (!queue.empty()) {
            size_t size {queue.size()};

            while (!d.empty()) {
                if (d.front() != d.back()) {
                    return false;
                } else {
                    d.pop_front();
                    if (!d.empty()) { d.pop_back(); }
                }
            }

            for (size_t i {0}; i < size; ++i) {
                TreeNode* current = queue.front();
                queue.pop();

                if (current->left) { 
                    queue.push(current->left); 
                    d.push_back(current->left->val);
                } else {
                    d.push_back(-1);
                }

                if (current->right) {
                    queue.push(current->right);
                    d.push_back(current->right->val);
                } else {
                    d.push_back(-1);
                }
            }
        }

        return true;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    Codec c;
    std::vector<std::pair<TreeNode*,bool>> input {
        {c.deserialize("[5,2,-3]"),false},
        {c.deserialize("[5,2,-5]"),false},
        {c.deserialize("[]"),true},
        {c.deserialize("[19]"),true},
        {c.deserialize("[5,2,7,1,1,8,8]"),false},
        {c.deserialize("[5,2,2,1,1,1,1]"),true},
        {c.deserialize("[5,2,2,1,8,8,1]"),true},
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.isSymmetric(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
