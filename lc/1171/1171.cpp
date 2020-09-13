// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Problem definition: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Accepted 2020-09-13

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>

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
        std::vector<int> sums;
        ListNode* current {head};
        while (current) {
            sums.push_back(current->val);
            current = current->next;
            auto size {sums.size()};
            if (size > 1) {
                sums[size-1] += sums[size-2];
            }

            for (size_t i = 0, prefix = 0; i < sums.size(); prefix = sums[i++]) {
                if ((sums[size-1] - prefix) == 0) {
                    sums.erase(sums.begin() + i, sums.end());
                }
            }
        }

        ListNode* start {nullptr};
        if (sums.size() > 0) {
            current = start = new ListNode(sums[0]);
            for (size_t i = 1; i < sums.size(); ++i) {
                current->next = new ListNode(sums[i] - sums[i-1]);
                current = current->next;
            }
        }
        return start;
    }
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
