// 1342. Number of Steps to Reduce a Number to Zero
// Problem definition: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// 2020-02-17

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

class Solution {
public:
    int numberOfSteps(int num) {
        int steps {0};
        while (num > 1) {
            steps += num & 0x1 ? 2 : 1;
            num >>= 1; 
        }
        return steps + 1;
    }
};

TEST_CASE("LC test cases", "[Number of Steps to Reduce a Number to Zero]") {
    std::vector<std::pair<int,int>> input {
        {14,6},{8,4},{123,12}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numberOfSteps(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
