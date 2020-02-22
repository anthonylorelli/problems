// 0930. Binary Subarrays With Sum
// Problem definition: https://leetcode.com/problems/binary-subarrays-with-sum/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& A, int S) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Binary Subarrays With Sum]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,int>> input {
        {{{1,0,1,0,1},2},4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numSubarraysWithSum(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
