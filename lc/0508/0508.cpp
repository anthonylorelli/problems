// 0508. Most Frequent Subtree Sum
// Problem definition: https://leetcode.com/problems/most-frequent-subtree-sum/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    std::vector<int> findFrequentTreeSum(TreeNode* root) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    Codec c;
    std::vector<std::pair<TreeNode*,std::vector<int>>> input {
        {c.deserialize("[5,2,-3]"),{2,-3,4}},
        {c.deserialize("[5,2,-5]"),{2}}
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
