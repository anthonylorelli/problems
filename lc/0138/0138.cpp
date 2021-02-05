// 0133. Clone Graph
// Problem definition: https://leetcode.com/problems/clone-graph/
// Accepted 2021-02-04
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*,Node*> map;
        return cloneGraph(node, map);
    }

    Node* cloneGraph(Node* node, std::unordered_map<Node*,Node*>& map) {
        if (!node) { return nullptr; }

        Node* clone = new Node(node->val, node->neighbors);
        map[node] = clone;

        for (auto& neighbor : clone->neighbors) {
            neighbor = map.count(neighbor) ? map[neighbor] :
                cloneGraph(neighbor, map);
        }

        return clone;
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
