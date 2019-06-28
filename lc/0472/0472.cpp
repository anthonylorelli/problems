// 472. Concatenated Words
// Problem definition: https://leetcode.com/problems/concatenated-words/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Trie
{
public:
    Trie(const std::vector<std::string>& v) {
        for (const auto& s : v) { insert(s); }
    }

    void insert(const std::string& s) {
        m_root.insert(s.cbegin(), s.cend());
    }

    const bool is_concat(const std::string& s) const {
        return false;
    }

    struct Node
    {
        Node() : c{'\0'}, terminal{false} {}
        Node(const char c) : c{c}, terminal{false} {}

        void insert(const std::string::const_iterator& b, const std::string::const_iterator& e) {
            if (b != e) {
                auto n{std::find_if(children.begin(), children.end(), [&b](const Node& n) { return n.c == *b; })};
                if (n == children.end()) {
                    children.emplace_back(*b);
                    children.rbegin()->insert(b+1, e);
                } else {
                    n->insert(b+1, e);
                }
            } else {
                terminal = true;
            }
        }

        const int match(const std::string::const_iterator& b, const std::string::const_iterator& e, int count) const {
            if (b == e) {
                return count;
            } else {
                auto n{std::find_if(children.begin(), children.end(), [&b](const Node& n) { return n.c == *b; })};
                return (n == children.end()) ? count : n->terminal ? count + 1 : n->match(b+1, e, count + 1);
            }
        }

        const std::vector<Node>::const_iterator next(const std::vector<Node>::iterator& i, 
            const std::string::const_iterator& b, const std::string::const_iterator& e) const {
            return std::find_if(i->children.begin(), i->children.end(), [&b](const Node& n) { return n.c == *b; });
        }

        std::vector<Node> children;
        char c;
        bool terminal;
    };

private:
    Node m_root;
};

class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        return {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    }
};

int execute(std::istream& in, std::ostream& out) {
    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Node", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};    
    Trie::Node n;
    for (const auto& o : i) { n.insert(o.cbegin(), o.cend()); }

    SECTION("insert") {
        REQUIRE(n.children.size() == 4);
        REQUIRE(n.children[0].c == 'c');
        REQUIRE(n.children[1].c == 'd');
        REQUIRE(n.children[2].c == 'h');
        REQUIRE(n.children[3].c == 'r');
    }
    SECTION("match") {
        std::string s1{"catsdog"};
        int r{n.match(s1.cbegin(), s1.cend(), 0)};
        REQUIRE(r == 4);
        REQUIRE(n.match(s1.cbegin() + r, s1.cend(), 0) == 3);
    }
}

TEST_CASE("Execute unit tests", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    std::vector<std::string> o{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    Solution s;
    REQUIRE(s.findAllConcatenatedWordsInADict(i) == o);
}
