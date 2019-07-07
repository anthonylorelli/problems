// 72. Edit Distance
// Problem definition: https://leetcode.com/problems/edit-distance/
// Accepted ?

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

enum class Op { Insert, Delete, Substitute, None };

struct Cell {
    int cost;
    Op parent;
};


class Solution {
private:
    void row_init(std::vector<std::vector<Cell>>& m, int i) {
        m[0][i].cost = i;
        m[0][i].parent = (i > 0) ? Op::Insert : Op::None;
    }

    void column_init(std::vector<std::vector<Cell>>& m, int i) {
        m[i][0].cost = i;
        m[i][0].parent = (i > 0) ? Op::Delete : Op::None;
    }

    int match(const char c1, const char c2) {
        return c1 == c2 ? 0 : 1;
    }

    int indel(const char c) { return 1; }

    Cell& goal(std::vector<std::vector<Cell>>& m, std::string w1, std::string& w2) {
        return m[w1.length() - 1][w2.length() - 1];
    }

public:
    int minDistance(std::string word1, std::string word2) {
        const size_t max{std::max(word1.length(), word2.length()) + 1};
        std::vector<std::vector<Cell>> m(max, std::vector<Cell>(max));

        for (size_t i{0}; i < max; ++i) { 
            row_init(m, i); 
            column_init(m, i);
        }

        int comparison, insert, del;

        for (size_t i{1}; i < word1.length(); ++i) {
            for (size_t j{1}; j < word2.length(); ++j) {
                comparison = m[i-1][j-1].cost + match(word1[i], word2[j]);
                insert = m[i][j-1].cost + indel(word2[j]);
                del = m[i-1][j].cost + indel(word1[i]);

                m[i][j].cost = std::max(comparison, std::max(insert, del));
                m[i][j].parent = m[i][j].cost == comparison ? Op::Substitute : 
                    m[i][j].cost == insert ? Op::Insert : Op::Delete;
            }
        }

        auto& answer{goal(m, word1, word2)};
        return answer.cost;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Solutiont test", "[Edit Distance]") {
    SECTION("LC basic test case") {
        Solution s;
        std::string s1{"horse"};
        std::string s2{"row"};
        REQUIRE(s.minDistance(s1, s2) == 3);
    }
}