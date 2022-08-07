// 0338. Counting Bits
// Problem definition: https://leetcode.com/problems/counting-bits/
// Accepted 2022-08-01
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        if (n == 0) { return {0}; }
        if (n == 1) { return {0,1}; }

        std::vector<int> result = {0, 1, 1};
        int32_t largest_2 {2};
        
        for (int32_t i {3}; i <= n; ++i) {
            if ((i / largest_2) > 1) { largest_2 <<= 1; }
            const int32_t rem {i - largest_2};
            result.push_back(result[rem] + 1);
        }

        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<int,std::vector<int>>> input {
        {2, {0,1,1}}, {5, {0,1,1,2,1,2}}, {1, {0,1}},
        {3, {0,1,1,2}}, {4, {0,1,1,2,1}}, {6, {0,1,1,2,1,2,2}},
        {7, {0,1,1,2,1,2,2,3}}, {8, {0,1,1,2,1,2,2,3,1}},
        {9, {0,1,1,2,1,2,2,3,1,2}}, {10, {0,1,1,2,1,2,2,3,1,2,2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countBits(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
