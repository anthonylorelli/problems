// 0198. House Robber
// Problem definition: https://leetcode.com/problems/house-robber/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int max {0};
        for (int i {0}; i < nums.size(); ++i) {

        }
        return max;
    }

private:

};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{1,2,3,1},4},
        {{2,7,9,3,1},12}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.rob(testInput) == expected);
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
