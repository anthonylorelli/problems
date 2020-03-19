// 0915. Partition Array Into Disjoint Intervals
// Problem definition: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int partitionDisjoint(std::vector<int>& A) {
        int localMax{A[0]}, globalMax{A[0]}, count{1};
        std::for_each(A.begin() + 1, A.end(), [&](const auto i) {
            if (i > localMax) {
                count++;
                localMax = globalMax;
            } else {
                globalMax = std::max(globalMax, i);
            }
        });
        return count;
    }
};

TEST_CASE("LC test cases", "[Binary Subarrays With Sum]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{5,0,3,8,6},3},{{1,1,1,0,6,12},4},{{1,2},1},{{2,1},2},
        {{2,1,3},2},{{90,47,69,10,43,92,31,73,61,97},9},
        {{5,3,0,8,6},3}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.partitionDisjoint(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
