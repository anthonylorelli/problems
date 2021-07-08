// 0143. Reorder List
// Problem definition: https://leetcode.com/problems/reorder-list/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/listnode.h"

#include <algorithm>
#include <string>
#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            m_mid = m_length / 2;
        }
        m_length++;
        reorderList(head->next);
    }

private:
    std::stack<ListNode*> m_stack;
    int32_t m_length {0};
    int32_t m_mid {0};
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::string,std::string,std::string,bool>> input {
//         {"aabcc", "dbbca", "aadbbcbcac", true},
//         {"aabcc", "dbbca", "aadbbbaccc", false},
//         {"", "", "", true}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [s1, s2, s3, expected] = p;
//                 REQUIRE(s.isInterleave(s1, s2, s3) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
