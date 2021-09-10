// 0002. Add Two Numbers
// Problem definition: https://leetcode.com/problems/add-two-numbers/
// Accepted 2021-09-09
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }

    constexpr int32_t val(ListNode* node) {
        return node ? node->val : 0;
    }

    constexpr ListNode* next(ListNode* node) {
        return node ? node->next : nullptr;
    }

    ListNode* add(ListNode* l1, ListNode* l2, const int32_t carry) {
        if (!l1 && !l2) {
            return carry > 0 ? new ListNode{carry} : nullptr;
        }

        int32_t total = val(l1) + val(l2) + carry;
        int32_t place_val = total % 10;
        int32_t carry_next = total / 10;
        return new ListNode{place_val, add(next(l1), next(l2), carry_next)};
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
