// 0421. Maximum XOR of Two Numbers in an Array
// Problem definition: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Accepted 2021-02-17
// Cf. https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/850340/C%2B%2B-from-Brute-Force-To-using-Trie-Data-Structure
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <limits>

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
        TrieNode* head {new TrieNode{}};
        for (auto n : nums) {
            insert(n, head);
        }
        return xorMax(head, nums);
    }

    int xorMax(TrieNode* head, std::vector<int>& nums) {
        int32_t max = std::numeric_limits<int32_t>::min();

        for (auto n : nums) {
            int curXor {0};
            TrieNode* current {head};

            for (int32_t i {31}; i >= 0; --i) {
                if ((n >> i) & 1) {
                    if (current->left) {
                        curXor += std::pow(2,i);
                        current = current->left;
                    } else {
                        current = current->right;
                    }
                } else {
                    if (current->right) {
                        curXor += std::pow(2,i);
                        current = current->right;
                    } else {
                        current = current->left;
                    }
                }
            }

            max = std::max(max, curXor);
        }

        return max;
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
