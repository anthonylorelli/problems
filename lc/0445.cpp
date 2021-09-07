// 0445. Add Two Numbers II
// Problem definition: https://leetcode.com/problems/add-two-numbers-ii/
// Accepted 2021-09-06
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int32_t count_l1 {count(l1, 0)}, count_l2 {count(l2, 0)};
        if (count_l2 > count_l1) {
            std::swap(l1, l2);
            std::swap(count_l1, count_l2);
        }
        l2 = pad(l2, count_l1 - count_l2);
        int32_t carry {0};
        auto head = add(l1, l2, &carry);
        return carry > 0 ? new ListNode{carry, head} : head;
    }

    constexpr ListNode* add(ListNode* l1, ListNode* l2, int32_t* carry) const {
        if (!l1 && !l2) {
            return nullptr;
        }
        int32_t carry_next {0};
        auto next = add(l1->next, l2->next, &carry_next);
        int32_t value = l1->val + l2->val + carry_next;
        auto head = new ListNode{value % 10, next};
        *carry = value / 10;
        return head;
    }

    constexpr int32_t count(ListNode* node, int32_t n) const {
        return node ? count(node->next, n + 1) : n;
    }

    constexpr ListNode* pad(ListNode* node, int32_t count) const {
        auto head {node};
        while (count > 0) {
            head = new ListNode{0, head};
            count--;
        }
        return head;
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
