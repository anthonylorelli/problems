// 0203. Remove Linked List Elements
// Problem definition: https://leetcode.com/problems/remove-linked-list-elements/
// 2020-02-19

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};
/* */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* current {head};
        ListNode* prev {nullptr};

        while (current) {
            if (current->val == val) {
                if (!prev) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
            } else {
                prev = current;
            }
            current = current->next;
        }
        return head;
    }
};

// TEST_CASE("LC test cases", "[Remove Linked List Elements]") {
//     std::vector<std::pair<int,int>> input {
//         {2,2}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) { 
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.removeElement(testInput.first, testInput.second) == expected.second);
//                 REQUIRE(testInput.first == expected.first);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
