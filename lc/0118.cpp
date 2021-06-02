// 0118. Pascal's Triangle
// Problem definition: https://leetcode.com/problems/pascals-triangle/
// Accepted 2021-06-01
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include <iostream>

template <typename T, typename U>
void for_pair(T a_begin, T a_end, T b_begin, const U& binop) {
    for (; a_begin != a_end; ++a_begin, ++b_begin) {
        binop(*a_begin, *b_begin);
    }
}

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 1) { return {{1}}; }
        std::vector<std::vector<int>> result(numRows);
        result[0].push_back(1);
        for_pair(result.begin() + 1, result.end(), result.begin(), 
            [](auto& a, auto& b) {
                std::adjacent_difference(b.begin(), b.end(), std::back_inserter(a), std::plus<>());
                a.push_back(1);
            });

        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<int,std::vector<std::vector<int>>>> input {
        {1,{{1}}},{2,{{1},{1,1}}},{3,{{1},{1,1},{1,2,1}}}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, expected] = p;
                REQUIRE(Solution{}.generate(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
