// 0915. Partition Array Into Disjoint Intervals
// Problem definition: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int partitionDisjoint(std::vector<int>& A) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Binary Subarrays With Sum]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{5,0,3,8,6},3},{{1,1,1,0,6,12},4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.partitionDisjoint(testInput.first) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
