// 0445. Add Two Numbers II
// Problem definition: https://leetcode.com/problems/add-two-numbers-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return nullptr;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<std::vector<int>>,std::vector<std::vector<int>>>> input {
//         {{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}},
//             {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}}},
//         {{{1,2},{2,1}},{{0,0},{0,1},{1,0},{1,1}}}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.pacificAtlantic(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
