// 0241. Different Ways to Add Parentheses
// Problem definition: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        return {};        
    }

    template<typename It, typename End>
    void rand(It begin, End end, std::stack<char>& op, std::stack<int>& rands) {
        rands.push(*begin - '0');
    }

    template<typename It, typename End>
    void op(It begin, End end, std::stack<char>& op, std::stack<int>& rands) {
        if (begin == end) {
            reduce(op, rands);
            return;
        }
        
    }

    void reduce(std::stack<char>& op, std::stack<int>& rands) {
        int answer {rands.top()};
        rands.pop();
        while (!op.empty()) {
            switch (op.top()) {
            case '+':
                answer = rands.top() + answer;
                break;
            case '-':
                answer = rands.top() - answer;
                break;
            case '*':
                answer = rands.top() * answer;
                break;
            }
            rands.pop();
            op.pop();
        }
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
