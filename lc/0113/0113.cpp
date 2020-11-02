// 0113. Path Sum II
// Problem definition: https://leetcode.com/problems/path-sum-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <array>

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        pathSum(root, 0, sum);
        return m_result;
    }

private:
    void pathSum(const TreeNode* node, const int sum, const int target) {
        if (!node) { return; }
        m_path.push_back(node->val);
        const int node_sum {node->val + sum};
        if (!node->left && !node->right && node_sum == target) {
            m_result.push_back(m_path);
            return;
        }
        if (node->left) {
            pathSum(node->left, node_sum, target);
            m_path.pop_back();
        }
        if (node->right) {
            pathSum(node->right, node_sum, target);
            m_path.pop_back();
        }
    }

    std::vector<std::vector<int>> m_result;
    std::vector<int> m_path;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::pair<std::string,int>,std::vector<std::vector<int>>>> input {
        {{"[5,4,8,11,null,13,4,7,2,null,null,5,1]",22},
            {{5,4,11,2},{5,8,4,5}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Codec c; 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.pathSum(c.deserialize(testInput.first), testInput.second) == expected);
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
