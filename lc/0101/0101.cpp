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
        return false;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    Codec c;
    std::vector<std::pair<TreeNode*,bool>> input {
        {c.deserialize("[5,2,-3]"),false},
        {c.deserialize("[5,2,-5]"),false},
        {c.deserialize("[]"),true},
        {c.deserialize("[19]"),true}
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
