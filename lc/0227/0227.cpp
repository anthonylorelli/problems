// 0227. Basic Calculator II
// Problem definition: https://leetcode.com/problems/basic-calculator-ii/
// Accepted 2020-12-08
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <deque>
#include <sstream>

class Solution {
public:
    int calculate(std::string s) {
        std::istringstream in{s};
        std::deque<int> stack;
        int lhs {0}, rhs {0};
        char op {'\0'};
        in >> lhs;
        stack.push_back(lhs);
        while (in >> op) {
            in >> rhs;
            switch (op) {
            case '+':
                stack.push_back(rhs);
                break;
            case '-':
                stack.push_back(-rhs);
                break;
            case '/':
                lhs = stack.back();
                stack.pop_back();
                lhs /= rhs;
                stack.push_back(lhs);
                break;
            case '*':
                lhs = stack.back();
                stack.pop_back();
                lhs *= rhs;
                stack.push_back(lhs);
                break;
            default:
                break;
            }
        }
        while (stack.size() > 1) {
            lhs = stack.front();
            stack.pop_front();
            rhs = stack.front();
            stack.pop_front();
            lhs += rhs;
            stack.push_front(lhs);
        }
        return stack.front();
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::string,int>> input {
        {"3+2*2", 7},
        {"3/2", 1},
        {"3+5 / 2", 5},
        {"3", 3},
        {"1/2", 0},
        {"1-1+1", 1},
        {"0-2147483647",-2147483647}
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
