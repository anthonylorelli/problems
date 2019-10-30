// 0396. Rotate Function
// Problem definition: https://leetcode.com/problems/rotate-function/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& A) {
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
