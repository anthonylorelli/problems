// 0241. Different Ways to Add Parentheses
// Problem definition: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

class Expr {
public:
    Expr(Expr* expr) : m_expr{expr}, m_n{0} {}
    Expr(int n) : m_expr{nullptr}, m_n{n} {}
    Expr(Expr* expr, int n) : m_expr{expr}, m_n{n} { }

    int operator()() {
        return m_expr ? (*m_expr)(m_n) : m_n;
    }

    virtual int operator()(const int i) = 0;

protected:
    Expr* m_expr;
    int m_n;
};

class AddExpr : public Expr {
public:
    AddExpr(Expr* expr) : Expr(expr) {}
    AddExpr(int n) : Expr(n) {}
    int operator()(const int i) override {
        return m_expr ? (*m_expr)() + i : i + m_n;
    }
};

class SubExpr : public Expr {
public:
    SubExpr(Expr* expr) : Expr(expr) {}
    SubExpr(int n) : Expr(n) {}
    int operator()(const int i) override {
        return m_expr ? (*m_expr)() - i : i - m_n;
    }
};

class MultExpr : public Expr {
public:
    MultExpr(Expr* expr) : Expr(expr) {}
    MultExpr(int n) : Expr(n) {}
    int operator()(const int i) override {
        return m_expr ? (*m_expr)() * i : i * m_n;
    }
};

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        op(expression.begin() + 1, expression.end(), [&expression]() { return expression[0] - '0'; });
        return m_result;
    }

    //template <typename It, typename End, typename Expr>
    //void op(It begin, End end, const Expr& expr) {
    template <typename Expr>
    void op(std::string::iterator begin, std::string::iterator end, const Expr& expr) {
        if (begin == end) {
            m_result.push_back(expr());
        }

        auto n = expr();

        switch (*begin) {
        case '+':
            rand(begin + 1, end, [&n](const int i) { return i + n; });
            rand(begin + 1, end, [&expr](const int i) { return i + expr(); });
            break;
        case '-':
            rand(begin + 1, end, [&n](const int i) { return i - n; });
            rand(begin + 1, end, [&expr](const int i) { return i - expr(); });
            break;
        case '*':
            rand(begin + 1, end, [&n](const int i) { return i * n; });
            rand(begin + 1, end, [&expr](const int i) { return i * expr(); });
            break;
        }
    }

    //template <typename It, typename End, typename Expr>
    //void rand(It begin, End end, const Expr& expr) {
    template <typename Expr>
    void rand(std::string::iterator begin, std::string::iterator end, const Expr& expr) {
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
