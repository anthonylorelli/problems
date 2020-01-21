// 1092. Shortest Common Supersequence
// Problem definition: https://leetcode.com/problems/shortest-common-supersequence/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <unordered_map>

class Trie {
public:
    template <typename It>
    void insert(const It& b, const It& e) {
        if (b != e) {
            bool terminal { b + 1 == e };
            if (!m_children.count(*b)) {
                m_children.insert({*b, std::make_pair(std::make_unique<Trie>(), terminal)});
            } else {
                m_children[*b].second = terminal;
            }
            m_children[*b].first->insert(b + 1, e);
        }
    }

    template <typename It>
    int match(const It& b, const It& e) {
        return match(b, e, 0);
    }

private:
    template <typename It>
    int match(const It& b, const It& e, const int prefix) {
        if (b != e && m_children.count(*b)) {
            int sum {prefix + 1};
            int rest {m_children[*b].first->match(b+1, e, sum)};
            return (m_children[*b].second && !rest) ? sum : rest;
        }
        return 0;
    }

    std::unordered_map<char, std::pair<std::unique_ptr<Trie>,bool>> m_children;
};

class SuffixTree {
public:
    SuffixTree(const std::string& s) {
        auto b {s.begin()};
        auto e {s.end()};
        while (b != e) { m_trie.insert(b++, e); }
    }

    int match(const std::string::iterator& b, const std::string::iterator& e) {
        return m_trie.match(b, e);
    }

    int match(const std::string& s) {
        return m_trie.match(s.begin(), s.end());
    }

private:
    Trie m_trie;
};

enum class Op {
    match,
    insert,
    remove,
    substitute
};

struct Cell {
    int cost;
    Op op;
};

Cell operator+(const int n, const Cell& c1) {
    return Cell{n+c1.cost, c1.op};
}

constexpr bool operator<(const Cell& c1, const Cell& c2) {
    return c1.cost < c2.cost;
}

class Distance {
private:
    void row_init(std::vector<std::vector<Cell>>& m, int i) const {
        m[0][i].cost = i;
    }

    void column_init(std::vector<std::vector<Cell>>& m, int i) const {
        m[i][0].cost = i;
    }

    Cell match_cost(const char c1, const char c2) const {
        return c1 == c2 ? Cell{0,Op::match} : Cell{1000,Op::substitute};
    }

    Cell insert_cost(const char c) const { return Cell{1,Op::insert}; }
    Cell remove_cost(const char c) const { return Cell{1,Op::remove}; }

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

        Cell comparison, insert, remove;

        for (size_t i{0}; i < word1.length(); ++i) {
            for (size_t j{0}; j < word2.length(); ++j) {
                comparison = m[i][j].cost + match_cost(word1[i], word2[j]);
                insert = m[i+1][j].cost + insert_cost(word2[j]);
                remove = m[i][j+1].cost + remove_cost(word1[i]);

                const size_t next_i{i+1}, next_j{j+1};
                m[next_i][next_j] = std::min({comparison, insert, remove});
            }
        }

        auto& answer{goal(m, word1, word2)};

        return answer.cost;
    }
};

class Solution {
public:
    std::string shortestCommonSupersequence(std::string str1, std::string str2) {
        SuffixTree s1 {str1}, s2 {str2};
        auto pre1 {s2.match(str1)};
        auto pre2 {s1.match(str2)};
        return pre1 > pre2 ? str2 + str1.substr(pre1) : str1 + str2.substr(pre2);
    }
};

TEST_CASE("LC test cases", "[Repeated Substring Pattern]") {
    std::vector<std::pair<std::pair<std::string,std::string>,std::string>> input {
        {{"abac","cab"},"cabac"},{{"cab","abac"},"cabac"},{{"abc","def"},"abcdef"},
        {{"bbbaaaba","bbababbb"},"bbabaaababb"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.shortestCommonSupersequence(testInput.first, testInput.second) == expected);
            });
    }
}

TEST_CASE("Suffix tree cases", "[Suffix tree cases]") {
    std::vector<std::pair<std::pair<std::string,std::string>,int>> input {
        {{"acab","cab"},3},{{"cab","abac"},2},{{"abac","abacab"},4}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                auto& [testInput, expected] = p;
                SuffixTree tree{testInput.first};
                REQUIRE(tree.match(testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
