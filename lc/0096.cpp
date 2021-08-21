// 0096. Unique Binary Search Trees
// Problem definition: https://leetcode.com/problems/unique-binary-search-trees/
// Accepted 2021-08.20
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"
#include "../inc/treenode.h"

#include <algorithm>
#include <vector>
#include <unordered_map>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct pair_hash {
    size_t operator()(std::pair<int,int> p) const noexcept {
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
    }
};

class Solution {
public:
    int numTrees(int n) {
        return generate(1, n);
    }

    int generate(const int32_t start, const int32_t end) {
        auto element = m_map.find({start,end});
        if (element != m_map.end()) {
            return element->second;
        }

        if (start > end) {
            return 0;
        }

        if (start == end) {
            return 1;
        }

        int32_t combos {0};
        for (int32_t i {start}; i <= end; ++i) {
            auto left = generate(start, i - 1);
            auto right = generate(i + 1, end);
            combos += left == 0 ? right : right == 0 ? left : right * left;
        }

        return m_map[{start,end}] = combos;
    }

private:
    std::unordered_map<std::pair<int,int>,int,pair_hash> m_map;
};

class Solution_iter {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

    std::vector<TreeNode*> generate(const int32_t start, const int32_t end) {
        if (start > end) {
            return {nullptr};
        }

        std::vector<TreeNode*> combos;
        for (int32_t i {start}; i <= end; ++i) {
            for (auto l : generate(start, i - 1)) {
                for (auto r : generate(i + 1, end)) {
                    combos.push_back(new TreeNode{i, l, r});
                }
            }
        }

        return combos;
    }
};

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int,std::vector<std::vector<int>>>> input {
//         {{2,3,6,7},7,{{2,2,3},{7}}},
//         {{2,3,5},8,{{2,3,3},{2,2,2,2},{3,5}}},
//         {{2},1,{}},{{1},1,{{1}}},
//         {{1},2,{{1,1}}},{{3,5,8},11,{{3,8},{3,3,5}}},
//         {{2,7,6,3,5,1},9,{{2,7},{2,6,1},{2,3,1,1,1,1},{2,3,3,1},{2,5,1,1},
//             {2,1,1,1,1,1,1,1},{2,2,3,1,1},{2,2,5},{2,2,1,1,1,1,1},{2,2,2,3},
//             {2,2,2,1,1,1},{2,2,2,2,1},{7,1,1},{6,3},{6,1,1,1},{3,5,1},{3,1,1,1,1,1,1},
//             {3,3,1,1,1},{3,3,3},{5,1,1,1,1},{1,1,1,1,1,1,1,1,1}}}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, target, expected] = p;
//                 REQUIRE(s.combinationSum(testInput, target) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
