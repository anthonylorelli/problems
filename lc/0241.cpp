// 0241. Different Ways to Add Parentheses
// Problem definition: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        op(expression.begin() + 1, expression.end(), [&expression]() { return expression[0] - '0'; });
        return m_result;
    }

    template <typename It, typename End, typename Expr>
    void op(It begin, End end, const Expr& expr) {
        if (begin == end) {
            m_result.push_back(expr());
        }

        auto n = expr();

        switch (*begin) {
        case '+':
            rand(begin + 1, end, [&n](const auto i) { return i + n; });
            rand(begin + 1, end, [&expr](const auto i) { return i + expr(); });
            break;
        case '-':
            rand(begin + 1, end, [&n](const auto i) { return i - n; });
            rand(begin + 1, end, [&expr](const auto i) { return i - expr(); });
            break;
        case '*':
            rand(begin + 1, end, [&n](const auto i) { return i * n; });
            rand(begin + 1, end, [&expr](const auto i) { return i * expr(); });
            break;
        }
    }

    template <typename It, typename End, typename Expr>
    void rand(It begin, End end, const Expr& expr) {
        int operand = *begin - '0';
        int n = expr(operand);
        op(begin + 1, end, [&n]() { return n; });
        op(begin + 1, end, [&expr, &operand]() { return expr(operand); });
    }

private:
    std::vector<int> m_result;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::vector<int>>> input {
        {"2-1-1",{0,2}},{"2*3-4*5",{-34,-14,-10,-10,10}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.diffWaysToCompute(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
