// 0989. Add to Array-Form Integer
// Problem definition: https://leetcode.com/problems/add-to-array-form-of-integer/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <tuple>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& A, int K) {
        int sum {0}; int mask {10};
        for (int i = 0; i < A.size(); ++i) {

        }
        return {};
    }
};

TEST_CASE("LC test cases", "[Add to Array-Form Integer]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,std::vector<int>>> input {
        {{{1,2,0,0},34},{1,2,3,4}}
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
