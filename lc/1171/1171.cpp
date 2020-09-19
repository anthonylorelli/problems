// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Problem definition: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Accepted 2020-09-13

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>
#include <unordered_map>

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::unordered_map <int, ListNode*> map;
        ListNode* stub = new ListNode{0};
        stub->next = head;
        map[0] = stub;
        int sum {0};

        while (head) {
            sum += head->val;
            map[sum] = head;
            head = head->next;
        }

        head = stub;
        sum = 0;

        while (head) {
            sum += head->val;
            ListNode* temp {map[sum]};
            if (temp != head) {
                head->next = temp->next;
            }
            head = head->next;
        }

        return stub->next;
    }

    // ListNode* removeZeroSumSublists(ListNode* head) {
    //     std::vector<std::pair<int,ListNode*>> sums;
    //     ListNode* current {head};
    //     while (current) {
    //         sums.push_back({current->val,current});
    //         current = current->next;
    //         auto size {sums.size()};
    //         if (size > 1) {
    //             sums[size-1].first += sums[size-2].first;
    //         }

    //         for (size_t i = 0, prefix = 0; i < sums.size(); prefix = sums[i++].first) {
    //             if ((sums[size-1].first - prefix) == 0) {
    //                 sums.erase(sums.begin() + i, sums.end());
    //                 if (i > 0) {
    //                     sums[i-1].second->next = current->next;
    //                 }
    //             }
    //         }
    //     }

    //     return sums.size() > 0 ? head : nullptr;
    // }
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Core]") {
    Solution s;
    SECTION("LC test case 1") {
        std::vector<int> v = {1, 2, -3, 3, 1};
        std::vector<int> result = {3, 1}; // {1, 2, 1} is also acceptable
        REQUIRE(s.removeZeroSumSublists(nullptr) == nullptr);
    }
}
