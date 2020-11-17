// 0148. Sort List
// Problem definition: https://leetcode.com/problems/sort-list/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/listnode.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* mid {getMid(head)};
        ListNode* left {sortList(head)};
        ListNode* right {sortList(mid)};
        return merge(left, right);
    }

private:
    ListNode* getMid(ListNode* head) {
        return nullptr;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        return nullptr;
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
