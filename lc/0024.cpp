// 0024. Swaps Pairs
// Problem definition: https://leetcode.com/problems/swap-nodes-in-pairs/
// Accepted 2021-08-10
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <vector>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode sentinel {0, head};
        if (head && head->next) {
            sentinel.next = head->next;
            ListNode* next {sentinel.next->next};
            sentinel.next->next = head;
            head->next = swapPairs(next);
        }
        return sentinel.next;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int>> input {
//         {{10,9,2,5,3,7,101,18},4},{{0,1,0,3,2,3},4},{{7,7,7,7,7,7,7},1},
//         {{1,3,6,7,9,4,10,5,6},6}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.lengthOfLIS(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
