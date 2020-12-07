// 0227. Basic Calculator II
// Problem definition: https://leetcode.com/problems/basic-calculator-ii/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <stack>
#include <sstream>

class Solution {
public:
    int calculate(std::string s) {
        std::istringstream in{s};
        std::stack<int> stack;
        std::stack<char> ops;
        int lhs {0}, rhs {0};
        char op {'\0'};
        in >> lhs;
        stack.push(lhs);
        while (in) {
            in >> op >> rhs;
            switch (op) {
            case '+':
            case '-':
                stack.push(rhs);
                ops.push(op);
                break;
            case '/':
                lhs = stack.top();
                stack.pop();
                lhs /= rhs;
                stack.push(lhs);
                break;
            case '*':
                lhs = stack.top();
                stack.pop();
                lhs *= rhs;
                stack.push(lhs);
                break;
            default:
                break;
            }
        }
        while (!ops.empty()) {
            op = ops.top();
            ops.pop();
            rhs = stack.top();
            stack.pop();
            lhs = stack.top();
            stack.pop();
            if (op == '+') {
                lhs += rhs;
            } else {
                lhs -= rhs;
            }
            stack.push(lhs);
        }
        return stack.top();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,int>> input {
        {"3+2*2", 7},
        {"3/2", 1},
        {"3+5 / 2", 5}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.calculate(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
