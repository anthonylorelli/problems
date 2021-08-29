// 1013. Partition Array Into Three Parts With Equal Sum
// Problem definition: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Accepted 2020-04-12

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <numeric>

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& A) {
        int sum {std::accumulate(A.begin(), A.end(), 0)};
        if (sum % 3) { return false; }
        int target {sum / 3}, count {0};
        int acc = std::accumulate(A.begin(), A.end(), 0, [&count, &target](const int s, const int n) {
            if ((s + n) == target) {
                count++;
                return 0;
            } else {
                return s + n;
            }
        });
        return (target == 0 && count >= 3) || count == 3;
    }
};

TEST_CASE("LC test cases", "[Partition Array Into Three Parts With Equal Sum]") {
    std::vector<std::pair<std::vector<int>,bool>> input {
        {{0,2,1,-6,6,-7,9,1,2,0,1},true},{{0,2,1,-6,6,7,9,-1,2,0,1},false},
        {{3,3,6,5,-2,2,5,1,-9,4},true},{{10,-10,10,-10,10,-10,10,-10},true}
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
