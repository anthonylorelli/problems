// 0143. Reorder List
// Problem definition: https://leetcode.com/problems/reorder-list/
// Accepted 2021-07-09, 2021-07-12, 2021,07-13
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    void reorderList(ListNode* head) {
        std::vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        size_t left {0}, right {nodes.size() - 1};
        while (left < right) {
            nodes[left]->next = nodes[right];
            nodes[right--]->next = nodes[++left];
        }
        nodes[left]->next = nullptr;
    }
};

class SolutionLinkedList {
public:
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next) {
            return;
        }

        ListNode* right = reverse(split(head));
        merge(head, right);
    }

    ListNode* split(ListNode* head) {
        ListNode* right {head->next};
        while (right && right->next) {
            head = head->next;
            right = right->next->next;
        }
        right = head->next;
        head->next = nullptr;
        return right;
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

TEST_CASE("LC test cases", "[Core]") {
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

    SECTION("vector tests") {
        Solution s;
        ListNode* h1 = create({1,2,3,4});
        s.reorderList(h1);
        REQUIRE(to_string(h1) == "1->4->2->3->");

        ListNode* h2 = create({1,2,3,4,5});
        s.reorderList(h2);
        REQUIRE(to_string(h2) == "1->5->2->4->3->");

        ListNode* h3 = create({1});
        s.reorderList(h3);
        REQUIRE(to_string(h3) == "1->");

        ListNode* h4 = create({1,2});
        s.reorderList(h4);
        REQUIRE(to_string(h4) == "1->2->");
    }

    SECTION("split() tests") {
        SolutionLinkedList s;
        auto list1 = {1, 2, 3, 4, 5, 6};
        ListNode* head = create(list1);
        ListNode* right = s.split(head);
        REQUIRE(to_string(head) == "1->2->3->");
        REQUIRE(to_string(right) == "4->5->6->");

        auto list2 = {1, 2, 3, 4, 5, 6, 7};
        ListNode* h2 = create(list2);
        ListNode* r2 = s.split(h2);
        REQUIRE(to_string(h2) == "1->2->3->4->");
        REQUIRE(to_string(r2) == "5->6->7->");
    }

    SECTION("reverse() tests") {
        SolutionLinkedList s;
        auto list1 = {1, 2, 3, 4, 5, 6};
        ListNode* head = create(list1);
        ListNode* rev = s.reverse(head);
        REQUIRE(to_string(rev) == "6->5->4->3->2->1->");

        auto list2 = {1};
        ListNode* h2 = create(list2);
        REQUIRE(to_string(h2) == "1->");
        ListNode* r2 = s.reverse(h2);
        REQUIRE(to_string(r2) == "1->");

        auto list3 = {1, 2};
        ListNode* h3 = create(list3);
        ListNode* r3 = s.reverse(h3);
        REQUIRE(to_string(r3) == "2->1->");
    }

    SECTION("merge() tests") {
        SolutionLinkedList s;
        ListNode* l1 = create({1, 3, 5, 7});
        ListNode* r1 = create({2, 4, 6, 8});
        ListNode* merged1 = s.merge(l1, r1);
        REQUIRE(to_string(merged1) == "1->2->3->4->5->6->7->8->");

        ListNode* l2 = create({1});
        ListNode* r2 = create({2});
        ListNode* merged2 = s.merge(l2, r2);
        REQUIRE(to_string(merged2) == "1->2->");

        ListNode* l3 = create({1});
        ListNode* r3 = nullptr;
        ListNode* merged3 = s.merge(l3, r3);
        REQUIRE(to_string(merged3) == "1->");
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
