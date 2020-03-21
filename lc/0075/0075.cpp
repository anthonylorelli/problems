// 0075. Sort Colors
// Problem definition: https://leetcode.com/problems/sort-colors/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        
    }
};

TEST_CASE("LC test cases", "[Sort Colors]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{2,0,2,1,1,0},{0,0,1,1,2,2}}     
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE_NOTHROW(s.sortColors(testInput));
                REQUIRE(testInput == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
