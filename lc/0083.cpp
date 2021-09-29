// 0083. Remove Duplicates from Sorted List
// Problem definition: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Accepted 2021-09-28
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode sentinel {0, head};
        while (head) {
            auto val {head->val};
            auto next {head->next};
            if (next && val == next->val) {
                while (next && val == next->val) {
                    next = next->next;
                }
                head->next = next;
            } 
            
            head = head->next;
        }
        return sentinel.next;
    }

    ListNode* deleteDuplicates_rec(ListNode* head) {
        return deleteDuplicates(head, -101);
    }

    ListNode* deleteDuplicates(ListNode* head, int32_t prev) {
        if (!head) {
            return nullptr;
        }
        if (head->val == prev) {
            return deleteDuplicates(head->next, prev);
        }
        head->next = deleteDuplicates(head->next, head->val);
        return head;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::string,std::string,bool>> input {
//         {"anagram", "nagaram", true}, {"rat", "car", false}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, b, expected] = p;
//                 REQUIRE(s.isAnagram(testInput, b) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
