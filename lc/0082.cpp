// 0082. Remove Duplicates from Sorted List II
// Problem definition: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Accepted 2021-06-29
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>
#include <string>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode sentinel {0, head};
        ListNode* prev {&sentinel};
        while (head) {
            auto val {head->val};
            if (head->next && val == head->next->val) {
                while (head->next && val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }

            head = head->next;
        }

        return sentinel.next;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,std::vector<std::string>>> input {
//         {{0,1,2,4,5,7},{"0->2","4->5","7"}},
//         {{0,2,3,4,6,8,9},{"0","2->4","6","8->9"}},
//         {{0,1,2,3,4},{"0->4"}},
//         {{},{}},
//         {{-1},{"-1"}},
//         {{0},{"0"}}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.summaryRanges(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
