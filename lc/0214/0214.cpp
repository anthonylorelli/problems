// 0214. Shortest Palindrome
// Problem definition: https://leetcode.com/problems/shortest-palindrome/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Trie {
public:
    void insert(std::string::iterator begin, std::string::iterator end) {
        Trie* current {nullptr};
        while (begin != end) {
            current = &m_children[*begin];
            begin++;
        }
    }

    template <typename T>
    int match(T b, T e) {
        Trie* current {this};
        int count {0};
        while (b++ != e) {
            if (current->m_children.count(*b)) {
                current = &current->m_children[*b];
                count++;
            } else {
                break;
            }
        }
        return count;
    }

private:
    std::unordered_map<char,Trie> m_children;
};

class SuffixTree {
public:
    void insert(std::string& s) {
        auto b {s.begin()};
        auto e {s.end()};
        while (b != e) { m_trie.insert(b++, e); }
    }

    template <typename T>
    int match(T b, T e) {
        return m_trie.match(b, e);
    }

private:
    Trie m_trie;
};

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        SuffixTree t;
        t.insert(s);
        int longestMatch {t.match(s.rbegin(), s.rend())};
        return "";
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[First Missing Positive]") {
    Solution s;
    std::vector<std::pair<std::string,std::string>> input {
        {"aacecaaa", "aaacecaaa"}, {"abcd", "dcbabcd"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](const auto& p) { 
                REQUIRE(s.shortestPalindrome(p.first) == p.second); 
            });
    }
}

TEST_CASE("Local test cases", "[First Missing Positive]") {
    //Solution s;
}
