// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Problem definition: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Accepted ?

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
        return nullptr;        
    }
};

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
