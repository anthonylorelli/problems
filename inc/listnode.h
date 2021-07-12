#pragma once

#include <string>
#include <initializer_list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::string to_string(const ListNode* head) {
    std::string s;
    const ListNode* iter = head;
    while (iter) {
        s += std::to_string(iter->val);
        s += "->";
        iter = iter->next;
    }
    return s;
}

ListNode* create(const std::initializer_list<int32_t>& list) {
    ListNode sentinel;
    ListNode* next {&sentinel};
    for (const auto n : list) {
        next->next = new ListNode(n);
        next = next->next;
    }
    return sentinel.next;
}
