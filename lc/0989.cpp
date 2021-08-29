// 0989. Add to Array-Form Integer
// Problem definition: https://leetcode.com/problems/add-to-array-form-of-integer/
// Accepted 2020-04-30

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& A, int K) {
        std::vector<int> result;
        std::transform(A.rbegin(), A.rend(), std::back_inserter(result), [&K](const auto n) {
            int current {n + (K % 10)};
            K = (K / 10) + (current / 10);
            return current % 10;
        });
        while (K > 0) {
            result.push_back(K % 10);
            K /= 10;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

TEST_CASE("LC test cases", "[Add to Array-Form Integer]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,std::vector<int>>> input {
        {{{1,2,0,0},34},{1,2,3,4}},{{{9,9,9,9},1},{1,0,0,0,0}},
        {{{0},10000},{1,0,0,0,0}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.addToArrayForm(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
