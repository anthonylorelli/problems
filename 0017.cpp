// 0017. Letter Combinations of a Phone Number
// Problem definition: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Accepted 2021-01-11
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0) {
            return {};
        }

        std::queue<std::string> queue;
        for (const auto c : m_map[digits[0]]) {
            queue.push(std::string{c});
        }

        std::for_each(digits.begin() + 1, digits.end(), [&](const auto c) {
            int n = queue.size();
            for (int i {0}; i < n; ++i) {
                const std::string& chars {m_map[c]};
                auto next = queue.front();
                queue.pop();
                for (const auto c : chars) {
                    next.push_back(c);
                    queue.push(next);
                    next.pop_back();
                }
            }
        });

        std::vector<std::string> result;
        while (!queue.empty()) {
            result.emplace_back(queue.front());
            queue.pop();
        }
        return result;
    }

private:
    std::unordered_map<char,std::string> m_map {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
        {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
        {'8',"tuv"}, {'9',"wxyz"}
    };
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string, std::vector<std::string>>> input {
        {"23",{"ad","ae","af","bd","be","bf","cd","ce","cf"}},
        {"",{}},
        {"2",{"a","b","c"}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.letterCombinations(testInput) == expected);
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
