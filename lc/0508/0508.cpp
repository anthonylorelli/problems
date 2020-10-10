// 0508. Most Frequent Subtree Sum
// Problem definition: https://leetcode.com/problems/most-frequent-subtree-sum/
// Accepted 2020-10-07, improved 2020-10-10
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findFrequentTreeSum(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    int traverse(const TreeNode* node, std::vector<int>& result) {
        if (!node) {
            return 0;
        }

        const int sum {node->val + traverse(node->left, result) + traverse(node->right, result)};
        const int count {++m_map[sum]};

        if (count == m_max) {
            result.push_back(sum);            
        } else if (count > m_max) {
            result.clear();
            result.push_back(sum);
            m_max = count;
        }

        return sum;
    }

    int m_max {1};
    std::unordered_map<int,int> m_map;
};

TEST_CASE("LC test cases", "[Core]") {
    Codec c;
    std::vector<std::pair<TreeNode*,std::vector<int>>> input {
        {c.deserialize("[5,2,-3]"),{2,-3,4}},
        {c.deserialize("[5,2,-5]"),{2}},
        {c.deserialize("[]"),{}},
        {c.deserialize("[19]"),{19}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findFrequentTreeSum(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
