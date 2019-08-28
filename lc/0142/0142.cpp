// 0142. Linked List Cycle II
// Problem definition: https://leetcode.com/problems/linked-list-cycle-ii/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

// Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) { return nullptr; }

        ListNode* slow {head->next};
        if (!slow) { return nullptr; }
        ListNode* fast {slow->next};
        
        while (fast != slow) {
            
        }
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Linked List Cycle II]") {
    Solution s;
    // SECTION("LC test case 1") {
    //     std::vector<int> i = {1, 2, 0};
    //     REQUIRE(s.firstMissingPositive(i) == 3);
    // }
    // SECTION("LC test case 2") {
    //     std::vector<int> i = {3, 4, -1, 1};
    //     REQUIRE(s.firstMissingPositive(i) == 2);
    // }
    // SECTION("LC test case 3") {
    //     std::vector<int> i = {7, 8, 9, 11, 12};
    //     REQUIRE(s.firstMissingPositive(i) == 1);
    // }    
    // SECTION("LC test case 4") {
    //     std::vector<int> i = {};
    //     REQUIRE(s.firstMissingPositive(i) == 1);
    // }
    // SECTION("LC test case 4") {
    //     std::vector<int> i = {1};
    //     REQUIRE(s.firstMissingPositive(i) == 2);
    // }
}

TEST_CASE("Local test cases", "[Linked List Cycle II]") {
    Solution s;
}
