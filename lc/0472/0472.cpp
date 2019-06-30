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

    const bool is_concat(std::string& s) {
        return is_concat(s.begin(), s.end(), m_root, 0);
    }

    struct Node;
    struct Result;

    const bool is_concat(const std::string::iterator& b, const std::string::iterator& e, Node& n, const int count) {
        std::string::iterator current{b};
        Node* activeNode{&n};
        while (current != e) {
            Result r{activeNode->contains_substring(current, e)};
            current = r.last;
            if (r.found) {
                bool substrConcat{is_concat(current, e, m_root, count + 1)};
                if (substrConcat) {
                    return true;
                } else {
                    activeNode = &r.next;
                }
            } else {
                return false;
            }
        }

        return count > 1;
    }

    struct Result
    {
        Result(const bool found, Node& next, const std::string::iterator& last) : found{found}, next{next}, last{last} {}
        const bool found;
        Node& next;
        const std::string::iterator last;
    };

    struct Node
    {
        Node() : c{'\0'}, terminal{false} {}
        Node(const char c) : c{c}, terminal{false} {}

        void insert(const std::string::const_iterator& b, const std::string::const_iterator& e) {
            if (b != e) {
                auto n{next(b)};
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

        const Result contains_substring(const std::string::iterator& b, const std::string::iterator& e) {
            if (b == e) {
                return Result(true, *this, b);
            } else {
                auto n{next(b)};
                if (n == children.end()) {
                    return Result(false, *this, b);
                } else if (n->terminal) {
                    return Result(true, *n, b + 1);
                } else {
                    return n->contains_substring(b + 1, e);
                }
            }
        }

        const std::vector<Node>::iterator next(const std::string::const_iterator& b) {
            return std::find_if(children.begin(), children.end(), [&b](const Node& n) { return n.c == *b; });
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
    SECTION("is_substring") {
        std::string s1{"catsdog"};
        Trie::Result r{n.contains_substring(s1.begin(), s1.end())};
        REQUIRE(r.found == true);
        REQUIRE(r.last - s1.begin() == 3);
    }
}

TEST_CASE("Trie", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    Trie t{i};
    SECTION("is_concat") {
        std::vector<std::string> o1{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
        for (auto& s : o1) {
            REQUIRE(t.is_concat(s) == true);
        }
        std::vector<std::string> o2{"catsdogcats1", "dogcatsdog2", "ratcatdogcat3"};
        for (auto& s : o2) {
            REQUIRE(t.is_concat(s) == false);
        }
        std::vector<std::string> o3{"cat", "cats", "dog", "rat", "hippopotamuses"};
        for (auto& s : o3) {
            REQUIRE(t.is_concat(s) == false);
        }
    }
}

TEST_CASE("Execute unit tests", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    std::vector<std::string> o{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    Solution s;
    REQUIRE(s.findAllConcatenatedWordsInADict(i) == o);
}
