// 0022. Generate Parentheses
// Problem definition: https://leetcode.com/problems/generate-parentheses/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <vector>

class Sequence {
private:
    std::vector<std::string> m_results;
    std::string m_s;
    int m_n;

    template <typename T>
    void generate(T current, int toOpen, int toClose) {
        if (toOpen == 0 && toClose == 0) {
            m_results.push_back(m_s);
        } else {
            if (toOpen > 0) {
                *current = '(';
                generate(current + 1, toOpen - 1, toClose + 1);
            } 
            
            if (toClose) {
                *current = ')';
                generate(current + 1, toOpen, toClose - 1);
            }
        }
    }

public:
    Sequence(int n) : m_s(n * 2, ' '), m_n{n} { }

    std::vector<std::string> generate() {
        generate(m_s.begin(), m_n, 0);
        return m_results;
    }
};

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        Sequence s{n};
        return s.generate();
    }
};

TEST_CASE("LC test cases", "[Generate Parentheses]") {
    std::vector<std::pair<int,std::vector<std::string>>> input {
        {3,{"((()))", "(()())","(())()","()(())","()()()"}},
        {1,{"()"}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.generateParenthesis(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
