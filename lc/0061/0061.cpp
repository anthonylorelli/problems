// 0061. Rotate List
// Problem definition: https://leetcode.com/problems/rotate-list/
// Accepted 20202-11-12
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/listnode.h"
#include "../../inc/serialize.h"

#include <stack>

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) { return head; }
        ListNode* first {head};
        ListNode* current {head};
        std::stack<ListNode*> stack;
        while (current) { 
            stack.push(current);
            current = current->next;
        }
        int moves = k % stack.size();
        for (int i {0}; i < moves; ++i) {
            ListNode* node = stack.top();
            stack.pop();
            node->next = first;
            first = node;
        }
        if (stack.size() > 0) {
            stack.top()->next = nullptr;
        }
        return first;
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
