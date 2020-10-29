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
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,int>> input {
        {"[3,2,3,null,3,null,1]", 7},
        {"[3,4,5,1,3,null,1]", 9}
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
