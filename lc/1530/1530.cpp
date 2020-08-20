// 1530. Number of Good Leaf Nodes Pairs
// Problem definition: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
// Accepted ?

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
    Solution() {
        m_adjacent.push_back({false,std::vector<int>{}});
    }

    int countPairs(TreeNode* root, int distance) {
        if (!root) { return 0; }
        find_adjacent(root, 0);
        m_visited.resize(m_adjacent.size(), false);

        m_limit = distance;
        int count {0};

        for (int vertex {0}; vertex < m_adjacent.size(); ++vertex) {
            if (m_adjacent[vertex].first) {
                count += search(vertex, 0);
                // std::cout << "\n";
            }
        }

        return count;
    }

private:
    int search(const int vertex, const int distance) {
        if (distance > m_limit || (m_adjacent[vertex].first && m_visited[vertex])) {
            //std::cout << vertex << " T ";
            return 0;
        }

        m_visited[vertex] = true;
        //std::cout << vertex << " ";

        if (m_adjacent[vertex].first && distance > 0) {
            //std::cout << " G ";
            return 1;
        }

        int count {0};

        for (const auto& neighbor : m_adjacent[vertex].second) {
            count += search(neighbor, distance + 1);
        }

        return count;
    }

    void find_adjacent(TreeNode* node, const int index) {
        //std::cout << "Node: " << node->val << " Index: " << index << "\n";
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
    //std::vector<bool> m_visited;
    std::unordered_set<std::pair<int,int>> m_found;
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