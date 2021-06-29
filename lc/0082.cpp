// 0082. Remove Duplicates from Sorted List II
// Problem definition: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.hpp"

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
        if (!head) { return nullptr; }
        deleteDuplicates(head->next, head);
        return head;        
    }

    void deleteDuplicates(ListNode* current, ListNode* prev) {
        prev->next = current;

        if (!current) { return; }

        if (current->val == prev->val) {
            prev->next = current->next;
        } else {
            prev = current;
        }

        deleteDuplicates(current->next, prev);
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
