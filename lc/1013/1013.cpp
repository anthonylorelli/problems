// 1013. Partition Array Into Three Parts With Equal Sum
// Problem definition: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& A) {
        return false;
    }
};

TEST_CASE("LC test cases", "[Partition Array Into Three Parts With Equal Sum]") {
    std::vector<std::pair<std::vector<int>,bool>> input {
        {{0,2,1,-6,6,-7,9,1,2,0,1},true},{{0,2,1,-6,6,7,9,-1,2,0,1},false},
        {{3,3,6,5,-2,2,5,1,-9,4},true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.canThreePartsEqualSum(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
