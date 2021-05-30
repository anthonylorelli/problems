// 0119. Pascal's Triangle II
// Problem definition: https://leetcode.com/problems/pascals-triangle-ii/
// Accepted 2021-05-29
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) { return {1}; }
        if (rowIndex == 1) { return {1,1}; }
        std::vector<int> v1(rowIndex + 1, 1);
        std::vector<int> v2(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            std::adjacent_difference(v1.begin(), v1.begin() + i, v2.begin(), std::plus<>());
            std::swap(v1, v2);
        }

        return v1;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<int>>> input {
        {3,{1,3,3,1}},{0,{1}},{1,{1,1}},{2,{1,2,1}},{4,{1,4,6,4,1}}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.getRow(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
