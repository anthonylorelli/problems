// 0138. Copy List With Random Pointer
// Problem definition: https://leetcode.com/problems/copy-list-with-random-pointer/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <unordered_map>
#include <queue>

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
        if (!head) { return nullptr; }

        std::unordered_map<uint64_t,Node*> map;
        std::queue<Node*> queue;
        queue.push(head);
        while (!queue.empty()) {
            Node* node = queue.front();
            queue.pop();
            if (node->next) {
                uint64_t next = reinterpret_cast<uint64_t>(node->next);
                if (!map.count(next)) {
                    queue.push(node->next);
                    map[next] = node;
                }
            }
            uint64_t random = reinterpret_cast<uint64_t>(node->random);
            if (!map.count(random)) {
                queue.push(node->random);
            }
        }
        if (queue.empty()) {
            return new Node(head->val);
        }
        Node* current = map.begin()->second;
        uint64_t val = reinterpret_cast<uint64_t>(current);
        while (map.count(val)) {
            current = map[val];
            val = reinterpret_cast<uint64_t>(current);
        }
        return copy(current);
    }

private:
    Node* copy(Node* head) {
        if (!head) { return nullptr; }
        Node* next = new Node(head->val);
        next->next = copy(head->next);
        return next;
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
