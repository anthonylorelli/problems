// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Problem definition: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <vector>

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
        std::vector<int> v = {5, 7, 7, 8, 8, 10};
        std::vector<int> a = {3, 4};
        REQUIRE(s.searchRange(v, 8) == a);
    }
    SECTION("LC test case 2") {
        std::vector<int> v = {5, 7, 7, 8, 8, 10};
        std::vector<int> a = {-1, -1};
        REQUIRE(s.searchRange(v, 6) == a);
    }
}
