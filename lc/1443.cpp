// 1443. Minimum Time to Collect All Apples in a Tree
// Problem definition: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Accepted 2020-08-04

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <forward_list>
#include <limits>

class Solution {
public:
    int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) {
        m_adjacent.resize(n);
        for (const auto& edge : edges) {
            m_adjacent[edge[0]].push_back(edge[1]);
            m_adjacent[edge[1]].push_back(edge[0]);
        }
        m_discovered.resize(n, false);
        return search(0, hasApple);
    }

private:
    int search(const int vertex, std::vector<bool>& has_apple) {
        int count {0};
        m_discovered[vertex] = true;

        for (const auto edge : m_adjacent[vertex]) {
            if (!m_discovered[edge]) {
                int sub = search(edge, has_apple);
                if (has_apple[edge] || sub > 0) {
                    sub += 2;
                }
                count += sub;
            }
        }

        return count;
    }

    std::vector<std::vector<int>> m_adjacent;
    std::vector<bool> m_discovered;
};

auto speed=[]() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

TEST_CASE("LC test cases", "[Core]") {
    SECTION("Case 1") {
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        std::vector<bool> has_apple = {false,false,true,false,true,true,false};
        int n {7};
        Solution s;
        REQUIRE(s.minTime(n, edges, has_apple) == 8);
    }
    SECTION("Case 2") {
        std::vector<std::vector<int>> edges = {{0,2},{0,3},{1,2}};
        std::vector<bool> has_apple = {false,true,false,false};
        int n {4};
        Solution s;
        REQUIRE(s.minTime(n, edges, has_apple) == 4);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
