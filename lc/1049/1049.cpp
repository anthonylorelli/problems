// 1049. Last Stone Weight II
// Problem definition: https://leetcode.com/problems/last-stone-weight-ii/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Last Stone Weight II]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2,7,4,1,8,1}, 1}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.lastStoneWeightII(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
