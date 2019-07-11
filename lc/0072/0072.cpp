// 72. Edit Distance
// Problem definition: https://leetcode.com/problems/edit-distance/
// Accepted 2019-07-10

/* 
Given two words word1 and word2, find the minimum number of operations required 
to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

enum class Op { Insert, Delete, Substitute, None };

struct Cell {
    int cost;
};

std::ostream& operator<<(std::ostream& o, const Cell& c) {
    o << std::setw(3) << std::setfill(' ') << c.cost;
    return o;
}

std::ostream& operator<<(std::ostream& o, const std::vector<std::vector<Cell>>& m) {
    for (const auto& r : m) {
        for (const auto& c : r) { o << c; }
        o << "\n";
    }
    return o;
}

class Solution {
private:
    void row_init(std::vector<std::vector<Cell>>& m, int i) const {
        m[0][i].cost = i;
    }

    void column_init(std::vector<std::vector<Cell>>& m, int i) const {
        m[i][0].cost = i;
    }

    int match_cost(const char c1, const char c2) const {
        return c1 == c2 ? 0 : 1;
    }

    int insert_cost(const char c) const { return 1; }
    int delete_cost(const char c) const { return 1; }

    Cell& goal(std::vector<std::vector<Cell>>& m, const std::string& w1, const std::string& w2) const {
        return m[w1.length()][w2.length()];
    }

public:
    int minDistance(std::string word1, std::string word2) const {
        const size_t max{std::max(word1.length(), word2.length()) + 1};
        std::vector<std::vector<Cell>> m(max, std::vector<Cell>(max));

        for (size_t i{0}; i < max; ++i) { 
            row_init(m, i); 
            column_init(m, i);
        }

        int comparison, insert, del;

        for (size_t i{0}; i < word1.length(); ++i) {
            for (size_t j{0}; j < word2.length(); ++j) {
                comparison = m[i][j].cost + match_cost(word1[i], word2[j]);
                insert = m[i+1][j].cost + insert_cost(word2[j]);
                del = m[i][j+1].cost + delete_cost(word1[i]);

                const size_t next_i{i+1}, next_j{j+1};
                m[next_i][next_j].cost = std::min(comparison, std::min(insert, del));
            }
        }

        auto& answer{goal(m, word1, word2)};

        //std::cout << m;
        
        return answer.cost;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Solutiont test", "[Edit Distance]") {
    SECTION("LC basic test case 1") {
        Solution s;
        std::string s1{"horse"};
        std::string s2{"ros"};
        REQUIRE(s.minDistance(s1, s2) == 3);
    }
    SECTION("LC basic test case 1") {
        Solution s;
        std::string s1{"intention"};
        std::string s2{"execution"};
        REQUIRE(s.minDistance(s1, s2) == 5);
    }
    SECTION("Test case from Skienna") {
        Solution s;
        std::string s1{"thou shalt not"};
        std::string s2{"you should not"};
        REQUIRE(s.minDistance(s1, s2) == 5);
    }
    SECTION("Modified test case from Skienna") {
        Solution s;
        std::string s1{"thou shalt not thou shalt not thou shalt not"};
        std::string s2{"you should not you should not you should not"};
        REQUIRE(s.minDistance(s1, s2) == 15);
    }
}
