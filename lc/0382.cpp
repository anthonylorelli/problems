// 0382. Linked List Random Node
// Problem definition: https://leetcode.com/problems/linked-list-random-node/
// Accepted 2020-12-10
// Cf. https://en.wikipedia.org/wiki/Reservoir_sampling
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/listnode.h"

#include <algorithm>
#include <random>
#include <cstdlib>

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : m_head{head} { std::srand(std::time(nullptr)); }
    
    /** Returns a random node's value. */
    int getRandom() {
        int choice {m_head->val}, context {1};
        ListNode* current {m_head};

        while (current) {
            if (random() < (1.0 / context)) {
                choice = current->val;
            }
            ++context;
            current = current->next;
        }

        return choice;
    }

private:
    float random() {
        return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    }

    ListNode* m_head;
};

// class Solution {
// public:
//     /** @param head The linked list's head.
//         Note that the head is guaranteed to be not null, so it contains at least one node. */
//     Solution(ListNode* head) : m_head{head}, m_gen{m_rd()}, m_dis{0.0, 1.0} { }
    
//     /** Returns a random node's value. */
//     int getRandom() {
//         int choice {m_head->val}, context {1};
//         ListNode* current {m_head};

//         while (current) {
//             if (m_dis(m_gen) < (1.0 / context)) {
//                 choice = current->val;
//             }
//             ++context;
//             current = current->next;
//         }

//         return choice;
//     }

// private:
//     ListNode* m_head;
//     std::random_device m_rd;
//     std::mt19937 m_gen;
//     std::uniform_real_distribution<> m_dis;
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

TEST_CASE("LC test cases", "[Core]") {
    // std::vector<std::pair<std::string,int>> input {
    //     {"3+2*2", 7},
    //     {"3/2", 1},
    //     {"3+5 / 2", 5},
    //     {"3", 3},
    //     {"1/2", 0},
    //     {"1-1+1", 1},
    //     {"0-2147483647",-2147483647}
    // };

    // SECTION("LC test cases") {
    //     std::for_each(std::begin(input), std::end(input),
    //         [&input](auto& p) {
    //             Solution s;
    //             auto& [testInput, expected] = p;
    //             REQUIRE(s.calculate(testInput) == expected);
    //         });
    // }
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
