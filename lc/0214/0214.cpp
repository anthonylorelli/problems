// 0214. Shortest Palindrome
// Problem definition: https://leetcode.com/problems/shortest-palindrome/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <unordered_map>
#include <list>

class Trie {
public:
    Trie() { }

    template <typename It>
    void insert(const It& b, const It& e) {
        if (b != e) {
            if (!m_children.count(*b)) {
                m_storage.emplace_back();
                m_children.insert({ *b, &*m_storage.rbegin() });
            }
            m_children[*b]->insert(b + 1, e);
        }
    }

    template <typename It>
    int match(const It& b, const It& e) {
        int count {0};
        if (b != e) {
            if (m_children.count(*b)) {
                count = m_children[*b]->match(b+1, e) + 1;
            }
        }
        return count;
    }

private:
    std::unordered_map<char, Trie*> m_children;
    std::list<Trie> m_storage;
};

class SuffixTree {
public:
    template <typename It>
    SuffixTree(const It b, const It& e) {
        auto i {b};
        while (i != e) { m_trie.insert(i++, e); }
    }

    int match(const std::string::iterator& b, const std::string::iterator& e) {
        return m_trie.match(b, e);
    }

private:
    Trie m_trie;
};

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        SuffixTree t(s.rbegin(), s.rend());
        int longestMatch {t.match(s.begin(), s.end())};
        size_t prefixLength {s.length() - longestMatch};
        std::string prefix(s.rbegin(), s.rbegin() + prefixLength);
        return prefix + s;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Shortest Palindrome]") {
    Solution s;
    std::vector<std::pair<std::string,std::string>> input {
        {"aacecaaa", "aaacecaaa"}, {"abcd", "dcbabcd"},
        {"ababbbabbaba", "ababbabbbababbbabbaba"} //"ababbabababbbabbaba"
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](const auto& p) { 
                REQUIRE(s.shortestPalindrome(p.first) == p.second); 
            });
    }
}

TEST_CASE("Local test cases", "[Shortest Palindrome]") {
    Solution s;
    std::vector<std::pair<std::string,std::string>> input {
        {"aaaa", "aaaa"}, {"d", "d"},
        {"abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcbabcdefghijklmnopqrstuvwxyz"},
        {"bbcd", "dcbbcd"}, {"", ""}
    };

    SECTION("Local test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](const auto& p) { 
                REQUIRE(s.shortestPalindrome(p.first) == p.second); 
            });
    }
}
