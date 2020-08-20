// 1530. Number of Good Leaf Nodes Pairs
// Problem definition: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Accepted 2020-08-20

#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"
#include "../../inc/treenode.h"
#include "../../inc/serialize.h"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if (!root) { return 0; }
        m_limit = distance;
        count_pairs(root);
        return m_count;  
    }

    int countPairsGenerlizedAdjacencyList(TreeNode* root, int distance) {
        if (!root) { return 0; }
        m_adjacent.push_back({false,std::vector<int>{}});
        find_adjacent(root, 0);
        m_visited.resize(m_adjacent.size(), std::vector<bool>(m_adjacent.size(), false));

        m_limit = distance;
        int count {0};

        for (int vertex {0}; vertex < m_adjacent.size(); ++vertex) {
            if (m_adjacent[vertex].first) {
                count += search(vertex, vertex, 0);
            }
        }

        return count;
    }

private:
    std::vector<int> count_pairs(const TreeNode* node) {
        if (!node) { return {}; }
        if (!node->left && !node->right) { return {1}; }
        std::vector left {count_pairs(node->left)};
        std::vector right {count_pairs(node->right)};
        for (const auto l : left) {
            for (const auto r : right) {
                if (l + r <= m_limit) {
                    m_count++;
                }
            }
        }

        std::vector<int> leaves;
        for (auto l : left) {
            if (++l < m_limit) {
                leaves.push_back(l);
            }
        }
        for (auto r : right) {
            if (++r < m_limit) {
                leaves.push_back(r);
            }
        }
        return leaves;
    }

    int search(const int start, const int vertex, const int distance) {
        if (distance > m_limit || m_visited[start][vertex] || (m_adjacent[vertex].first && m_visited[vertex][start])) {
            return 0;
        }

        m_visited[start][vertex] = true;

        if (m_adjacent[vertex].first && distance > 0) {
            return 1;
        }

        int count {0};

        for (const auto& neighbor : m_adjacent[vertex].second) {
            count += search(start, neighbor, distance + 1);
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
    int m_count {0};
    std::vector<std::vector<bool>> m_visited;
    std::vector<std::pair<bool,std::vector<int>>> m_adjacent;
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Core]") {
    SECTION("Case 1") {
        Codec c;
        TreeNode* root = c.deserialize("[15,66,55,97,60,12,56,null,54,null,49,null,9,null,null,null,null,null,90]");
        int distance {5};
        Solution s;
        REQUIRE(s.countPairs(root, distance) == 3);
    }
    SECTION("Case 2") {
        Codec c;
        TreeNode* root = c.deserialize("[1,2,3,null,4]");
        int distance {3};
        Solution s;
        REQUIRE(s.countPairs(root, distance) == 1);
    }
    SECTION("Case 3") {
        Codec c;
        TreeNode* root = c.deserialize("[1,2,3,4,5,6,7]");
        int distance {3};
        Solution s;
        REQUIRE(s.countPairs(root, distance) == 2);
    }
    SECTION("Case 4") {
        Codec c;
        TreeNode* root = c.deserialize("[100]");
        int distance {1};
        Solution s;
        REQUIRE(s.countPairs(root, distance) == 0);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

//              15 
//        66          55 
//   97     60     12     56 
// *  54   *  49  *  9   *  * 
//   *,*     *,90