// 0022. Generate Parentheses
// Problem definition: https://leetcode.com/problems/generate-parentheses/
// Accepted 2019-12-30

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <string>
#include <vector>

class Sequence {
private:
    int m_n;
    std::string m_s;
    std::vector<std::string>& m_results;

    template <typename T>
    void generate(const T& current, const int toOpen, const int toClose) {
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
    Sequence(int n, std::vector<std::string>& v) : m_s(n * 2, ' '), m_n{n}, m_results{v} { }

    void generate() {
        generate(m_s.begin(), m_n, 0);
    }
};

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> v;
        Sequence s{n, v};
        s.generate();
        return v;
    }
};

TEST_CASE("LC test cases", "[Generate Parentheses]") {
    std::vector<std::pair<int,std::vector<std::string>>> input {
        {4,{"(((())))","((()()))","((())())","((()))()","(()(()))",
            "(()()())","(()())()","(())(())","(())()()","()((()))",
            "()(()())","()(())()","()()(())","()()()()"}},
        {3,{"((()))", "(()())","(())()","()(())","()()()"}},
        {2,{"(())","()()"}},
        {1,{"()"}},
        {0,{""}}
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
