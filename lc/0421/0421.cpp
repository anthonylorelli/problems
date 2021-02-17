// 0421. Maximum XOR of Two Numbers in an Array
// Problem definition: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Accepted ?
// Cf. https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/850340/C%2B%2B-from-Brute-Force-To-using-Trie-Data-Structure
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

struct TrieNode {
    TrieNode* left;
    TrieNode* right;
};

TrieNode* insert(int value, TrieNode* head) {
    TrieNode* current = head;
    for (int32_t i {31}; i >= 0; --i) {
        int32_t bit = (value>>i)&1;
        if (bit == 0) {
            if (!current->left) {
                current->left = new TrieNode{};
            }
            current = current->left;
        } else {
            if (!current->right) {
                current->right = new TrieNode{};
            }
            current = current->right;
        }
    }
    return head;
}

class Solution {
public:
    int findMaximumXOR(std::vector<int>& nums) {
        return 0;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{3,10,5,25,2,8},28},
        {{0},0},
        {{2,4},6},
        {{8,10,2},10},
        {{14,70,53,83,49,91,36,80,92,51,66,70},127}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findMaximumXOR(testInput) == expected);
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
