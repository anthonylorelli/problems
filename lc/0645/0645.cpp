// 0645. Set Mismatch
// Problem definition: https://leetcode.com/problems/set-mismatch/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        return {};
    }
};

TEST_CASE("LC test cases", "[Set Mismatch]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{1,2,2,4},{2,3}}
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
