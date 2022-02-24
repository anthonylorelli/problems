// 0138. Copy List With Random Pointer
// Problem definition: https://leetcode.com/problems/copy-list-with-random-pointer/
// Accepted 2021-02-02
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*,Node*> map;
        return copy(head, map);
    }

    Node* copy(Node* head, std::unordered_map<Node*,Node*>& map) {
        if (!head) { return nullptr; }

        Node* copyHead = new Node(head->val);
        map[head] = copyHead;
        copyHead->next = copy(head->next, map);
        if (head->random) {
            copyHead->random = map[head->random];
        }
        return copyHead;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<int,int>> input {
//         {10,4},
//         {0,0},
//         {1,0}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.countPrimes(testInput) == expected);
//             });
//     }
// }

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
