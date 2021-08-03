// 0241. Different Ways to Add Parentheses
// Problem definition: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Accepted 2021-08-02
// Cf. https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/1005450/C%2B%2B-Recursive-AST-%2B-Memoization-with-segments-as-the-keys-%2B-explanation
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <unordered_map>

struct pair_hash {
    size_t operator()(std::pair<int,int> p) const noexcept {
        return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
    }
};

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        if (expression.empty()) { return {}; }
        auto nums = parse(expression);
        return evaluate(nums, 0, nums.size());
    }

    std::vector<int> parse(const std::string& expression) {
        std::vector<int> nums;
        std::istringstream str{expression};
        int rand {0};
        str >> rand;
        nums.push_back(rand);
        for (char op{'\0'}; str >> op;) {
            nums.push_back(op);
            str >> rand;
            nums.push_back(rand);
        }
        return nums;
    }

    std::vector<int> evaluate(const std::vector<int>& expr, size_t b, size_t e) {
        if (b + 1 == e) {
            return {expr[b]};
        }

        auto it = m_map.find({b,e});
        if (it != m_map.end()) {
            return it->second;
        }

        std::vector<int> result;
        for (auto i {b+1}; i < e; i += 2) {
            auto lhs = evaluate(expr, b, i);
            auto rhs = evaluate(expr, i + 1, e);
            for (const auto a : lhs) {
                for (const auto b : rhs) {
                    auto op = expr[i];
                    if (op == '+') {
                        result.push_back(a + b);
                    } else if (op == '-') {
                        result.push_back(a - b);
                    } else {
                        result.push_back(a * b);
                    }
                }
            }
        }

        m_map[{b,e}] = result;
        return result;
    }

private:
    std::unordered_map<std::pair<int,int>,std::vector<int>,pair_hash> m_map;
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::vector<int>>> input {
        {"2-1-1",{2,0}},{"2*3-4*5",{-34,-10,-14,-10,10}},{"1",{1}},
        {"11",{11}}
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
