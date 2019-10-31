// 0396. Rotate Function
// Problem definition: https://leetcode.com/problems/rotate-function/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& A) {
        int max {0}; // should be smallest negative
        auto size {A.size()};
        for (int offset {0}; offset < size; ++offset) {
            int sum {0};
            for (int i {1}; i < size; ++i) {
            }
        }
        return 0;
    }
};

TEST_CASE("LC test cases", "[Rotate Function]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,int>> input {
        {{4,3,2,6}, 26}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.swimInWater(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
