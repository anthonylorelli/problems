// 0148. Sort List
// Problem definition: https://leetcode.com/problems/sort-list/
// Accepted 2020-11-17
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/listnode.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* mid {halve(head)};
        ListNode* left {sortList(head)};
        ListNode* right {sortList(mid)};
        return merge(left, right);
    }

private:
    ListNode* halve(ListNode* head) {
        ListNode* midTail {nullptr};
        while (head && head->next) {
            midTail = !midTail ? head : midTail->next;
            head = head->next->next;
        }
        ListNode* mid = midTail->next;
        midTail->next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode headStub;
        ListNode* current {&headStub};

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        current->next = left ? left : right;
        return headStub.next;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::tuple<std::vector<int>,int,int>,bool>> input {
        {{{1,2,3,1},3,0}, true},
        {{{1,0,1,1},1,2}, true},
        {{{1,5,9,1,5,9},2,3}, false},
        {{{},0,0}, false},
        {{{1},0,0}, false},
        {{{1,1},1,0}, true},
        {{{1,2},1,0}, false},
        {{{8,7,15,1,6,1,9,15},1,3}, true},
        {{{1,5,9,1,5,9},2,3},false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                // Solution s;
                // auto& [testInput, expected] = p;
                // auto [input, k, t] = testInput;
                // REQUIRE(s.containsNearbyAlmostDuplicate(input, k, t) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
