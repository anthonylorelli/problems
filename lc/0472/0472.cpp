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
    void insert(const std::string& s) {

    }
private:
    struct Node
    {
        Node() : c{'\0'} {}
        Node(const char c) : c{c} {}

        void insert(std::string::iterator& i) {
            auto n{std::find(children.begin(), children.end(), [&i](Node& n) { return n.c == *i; })};
            if (n == children.end()) {
                children.emplace_back(*i);
                children.rbegin()->insert(i+1);
            } else {
                n->insert(i+1);
            }
        }

        std::vector<Node> children;
        char c;
    };

    Node m_root;
};

class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        
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

TEST_CASE("", "[Correct Move]") {
    SECTION("") {
        REQUIRE(true);
    }
}

TEST_CASE("Execute unit tests", "[Correct Move]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    std::vector<std::string> o{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    Solution s;
    REQUIRE(s.findAllConcatenatedWordsInADict(i) == o);
}
