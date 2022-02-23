// 0437. Path Sum III
// Problem definition: https://leetcode.com/problems/path-sum-iii/
// Accepted 2020-11-05
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        std::unordered_map<int,int> map;
        map[0] = 1;
        return pathSum(root, 0, sum, map);
    }

private:
    int pathSum(const TreeNode* node, const int current, const int target, std::unordered_map<int,int>& map) {
        if (!node) { return 0; }
        const int next = current + node->val;
        int result = map[next - target];
        ++map[next];
        result += pathSum(node->left, next, target, map);
        result += pathSum(node->right, next, target, map);
        --map[next];
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::pair<std::string,int>,int>> input {
        {{"[10,5,-3,3,2,null,11,3,-2,null,1]",8}, 3},
        {{"[1]",1},1},
        {{"[1]",2},0},
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
