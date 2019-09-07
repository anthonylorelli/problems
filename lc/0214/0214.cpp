// 0214. Shortest Palindrome
// Problem definition: https://leetcode.com/problems/shortest-palindrome/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <unordered_map>
#include <memory>

class Trie {
public:
    Trie() { }

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
    template <typename It>
    SuffixTree(const It& b, const It& e) {
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
        for (auto b {s.rbegin()}; b != s.rend(); ++b) {
            if (std::equal(b, s.rend(), s.begin())) {
                std::string prefix(s.rbegin(), b);
                return prefix + s;
            }
        }
        return s;
    }

    std::string shortestPalindromeSuffixTree(std::string s) {
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
        {"aaaa", "aaaa"}, {"aaa", "aaa"}, {"d", "d"},
        {"abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcbabcdefghijklmnopqrstuvwxyz"},
        {"bbcd", "dcbbcd"}, {"", ""}, {"dad", "dad"}
    };

    SECTION("Local test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](const auto& p) { 
                REQUIRE(s.shortestPalindrome(p.first) == p.second); 
            });
    }
}

TEST_CASE("TLE test cases", "[Shortest Palindrome]") {
    Solution s;
    std::vector<std::pair<std::string,std::string>> input {
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}
    };

    SECTION("Local test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](const auto& p) { 
                REQUIRE(s.shortestPalindrome(p.first) == p.second); 
            });
    }
}

        
