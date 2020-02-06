// 0189. Rotate Array
// Problem definition: https://leetcode.com/problems/rotate-array/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        
    }
};

TEST_CASE("LC test cases", "[Rotate Array]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,std::vector<int>>> input {
        {{{1,2,3,4,5,6,7},3},{5,6,7,1,2,3,4}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.flipAndInvertImage(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
