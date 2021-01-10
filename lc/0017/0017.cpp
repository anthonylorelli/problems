// 0017. Letter Combinations of a Phone Number
// Problem definition: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<string> letterCombinations(std::string digits) {
        return {};        
    }

private:
    std::unordered_map<char,std::string> {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
        {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
        {'8','tuv'}, {'9',"wxyz"}
    }
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
                auto& [testInput, target, expected] = p;
                REQUIRE(s.combinationSum2(testInput, target) == expected);
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
