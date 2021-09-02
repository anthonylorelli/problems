// 0417. Pacific Atlantic Water Flow
// Problem definition: https://leetcode.com/problems/pacific-atlantic-water-flow/
// Accepted 2021-08-31
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class OceanSearch {
public:
    OceanSearch(const int32_t m, const int32_t n) : m_atlantic(m, std::vector<bool>(n, false)),
        m_pacific(m, std::vector<bool>(n, false)), m_m{m}, m_n{n} { }

    std::vector<std::vector<int>> search(std::vector<std::vector<int>>& matrix) {
        for (int32_t i {0}; i < m_m; ++i) {
            dfs(matrix, m_pacific, i, 0);
            dfs(matrix, m_atlantic, i, m_n - 1);
        }
        for (int32_t i {0}; i < m_n; ++i) {
            dfs(matrix, m_pacific, 0, i);
            dfs(matrix, m_atlantic, m_m - 1, i);
        }
        return m_answer;
    }

    void dfs(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited, const int32_t i, const int32_t j) {
        if (visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        if (m_atlantic[i][j] && m_pacific[i][j]) {
            m_answer.push_back(std::vector<int>{i,j});
        }

        if (i + 1 < m_m && matrix[i + 1][j] >= matrix[i][j]) {
            dfs(matrix, visited, i + 1, j);
        }
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j]) {
            dfs(matrix, visited, i - 1, j);
        }
        if (j + 1 < m_n && matrix[i][j + 1] >= matrix[i][j]) {
            dfs(matrix, visited, i, j + 1);
        }
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j]) {
            dfs(matrix, visited, i, j - 1);
        }
    }

private:
    std::vector<std::vector<bool>> m_atlantic, m_pacific;
    std::vector<std::vector<int>> m_answer;
    int32_t m_m, m_n;
};

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
        OceanSearch search(matrix.size(), matrix[0].size());
        return search.search(matrix);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::vector<int>>,std::vector<std::vector<int>>>> input {
        {{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}},
            {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}}},
        {{{1,2},{2,1}},{{0,0},{0,1},{1,0},{1,1}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.pacificAtlantic(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
