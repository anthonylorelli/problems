// 0337. House Robber III
// Problem definition: https://leetcode.com/problems/house-robber-iii/
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
    int rob(TreeNode* root) {
        auto [left, right] = traverse(root);
        return std::max(left, right);
    }

private:
    std::pair<int,int> traverse(TreeNode* node) {
        if (!node) { return {0,0}; }

        auto left = traverse(node->left);
        auto right = traverse(node->right);

        return {
            std::max(left.first + right.first, left.second + right.second),
            left.first + right.first + node->val
        };
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,int>> input {
        {"[3,2,3,null,3,null,1]", 7},
        {"[3,4,5,1,3,null,1]", 9},
        {"[2,1,3,null,4]", 7}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Codec c; 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.rob(c.deserialize(testInput)) == expected);
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
