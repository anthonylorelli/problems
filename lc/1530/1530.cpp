// 1530. Number of Good Leaf Nodes Pairs
// Problem definition: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        add_adjacent(root, 0);
        m_visited.resize(m_adjacent.size(), false);

        m_limit = distance;
        int count {0};

        for (int vertex {0}; vertex < m_adjacent.size(); ++vertex) {
            if (m_adjacent[vertex].first) {
                count += search(vertex, 0);
            }
        }

        return count;
    }

private:
    int search(const int vertex, const int distance) {
        if (distance > m_limit || (m_adjacent[vertex].first && m_visited[vertex])) {
            return 0;
        }

        m_visited[vertex] = true;

        if (m_adjacent[vertex].first) {
            return 1;
        }

        int count {0};

        for (const auto& neighbor : m_adjacent[vertex].second) {
            if (m_adjacent[neighbor].first && m_visited[neighbor]) {
                continue;
            }

            count += search(neighbor, distance + 1);
        }

        return count;
    }

    void find_adjacent(TreeNode* node, const int index) {
        if (!node->left && !node->right) {
            m_adjacent[index].first = true;
            return;
        }

        if (node->left) {
            add_adjacent(node->left, index);
        }

        if (node->right) {
            add_adjacent(node->right, index);
        }
    }

    void add_adjacent(TreeNode* node, const int index) {
        int next_index = m_adjacent.size();
        m_adjacent.push_back({false,std::vector<int>{}});
        m_adjacent[index].second.push_back(next_index);
        m_adjacent[next_index].second.push_back(index);
        find_adjacent(node, next_index);
    }

    int m_limit {0};
    std::vector<bool> m_visited;
    std::vector<std::pair<bool,std::vector<int>>> m_adjacent;
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

// TEST_CASE("LC test cases", "[Core]") {
//     SECTION("Case 1") {
//         std::string input {"abcabcbb"};
//         Solution s;
//         REQUIRE(s.lengthOfLongestSubstring(input) == 3);
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
