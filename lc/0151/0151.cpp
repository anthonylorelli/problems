// 0151. Reverse Words in a String
// Problem definition: https://leetcode.com/problems/reverse-words-in-a-string/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        auto predicate = [](const char c) { return static_cast<bool>(std::isspace(c)); };
        auto start_delta = std::distance(s.begin(), std::find_if_not(s.begin(), s.end(), predicate));
        auto end_delta = std::distance(s.rbegin(), std::find_if_not(s.rbegin(), s.rend(), predicate));
        std::string result;
        bool isw{false};
        std::copy_if(s.rbegin() + end_delta, s.rend() - start_delta, std::back_inserter(result), [&](const auto c) {
            bool prevws = isw;
            isw = predicate(c);
            return !(prevws && isw);
        });
        for (auto start {result.begin()}; start != result.end(); ) {
            auto end = std::adjacent_find(start, result.end(), [](const auto a, const auto b) {
                return std::isspace(a) && !std::isspace(b);
            });
            std::reverse(start, end);
            start = end == result.end() ? end : end + 1;
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string>> input {
        {"the sky is blue","blue is sky the"},
        {"  hello world  ","world hello"},
        {"a good   example","example good a"},
        {"  Bob    Loves  Alice   ","Alice Loves Bob"},
        {"Alice does not even like bob","bob like even not does Alice"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.reverseWords(testInput) == expected);
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
