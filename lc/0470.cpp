// 0470. Implement Rand10() Using Rand7()
// Problem definition: https://leetcode.com/problems/implement-rand10-using-rand7/
// 2020-02-12
// Cf. https://en.wikipedia.org/wiki/Rejection_sampling

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <limits>

int rand7();

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row, column, index;
        do {
            row = rand7();
            column = rand7();
            index = column + (row - 1) * 7;
        } while (index > 40);
        return 1 + (index - 1) % 10;
    }
};

// TEST_CASE("LC test cases", "[Implement Rand10() Using Rand7()]") {
//     std::vector<std::pair<std::vector<std::vector<int>>,int>> input {
//         {{{1,3,1},{1,5,1},{4,2,1}}, 7}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) { 
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.minPathSum(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
