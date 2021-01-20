// 0209. Minimum Size Subarray Sum
// Problem definition: https://leetcode.com/problems/minimum-size-subarray-sum/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        return 0;        
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<int>,int>> input {
        {7,{2,3,1,2,4,3},2}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [size, testInput, expected] = p;
                REQUIRE(s.minSubArrayLen(size, testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
