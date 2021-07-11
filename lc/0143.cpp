// 0143. Reorder List
// Problem definition: https://leetcode.com/problems/reorder-list/
// Accepted 2021-07-09
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <string>
#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) {
            return;
        }

        ListNode* right = reverse(split(head));
        merge(head, right);
    }

    ListNode* split(ListNode* head) {
        ListNode* right {head};
        while (right && right->next) {
            head = head->next;
            right = right->next->next;
        }
        return head->next;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* tail {node};
        ListNode* head {node->next};
        tail->next = nullptr;
        while (head) {
            ListNode* next {head->next};
            head->next = tail;
            tail = head;
            head = next;
        }
        return tail;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* it_left {left};
        ListNode* it_right {right};
        while (it_left && it_right) {
            ListNode* left_next {it_left->next};
            ListNode* right_next {it_right->next};
            it_left->next = it_right;
            it_right->next = left_next;
            it_left = left_next;
            it_right = right_next;
        }
        return left;
    }
};

class SolutionStack {
public:
    void reorderList(ListNode* head) {
        traverse(head);
        ListNode* current {head};
        while (m_mid-- > 0) {
            ListNode* next {m_stack.top()};
            m_stack.pop();
            next->next = current->next;
            current->next = next;
            current = next->next;
        }
        if (current) {
            current->next = nullptr;
        }
    }

    void traverse(ListNode* head) {
        if (!head) {
            m_mid = m_length / 2;
            return;
        }
        m_length++;
        m_stack.push(head);
        traverse(head->next);
    }

private:
    std::stack<ListNode*> m_stack;
    int32_t m_length {0};
    int32_t m_mid {0};
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::string,std::string,std::string,bool>> input {
//         {"aabcc", "dbbca", "aadbbcbcac", true},
//         {"aabcc", "dbbca", "aadbbbaccc", false},
//         {"", "", "", true}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [s1, s2, s3, expected] = p;
//                 REQUIRE(s.isInterleave(s1, s2, s3) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}