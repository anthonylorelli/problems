// 0049. Group Anagrams
// Problem definition: https://leetcode.com/problems/group-anagrams/
// Accepted 2021-08-11
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string,std::vector<std::string>> map;
        for (const auto& s : strs) {
            std::string alpha {s};
            std::sort(alpha.begin(), alpha.end());
            map[alpha].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto& [key, value] : map) {
            result.push_back(std::move(value));
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::string>,std::vector<std::vector<std::string>>>> input {
        {{"eat","tea","tan","ate","nat","bat"},{{"eat","tea","ate"},{"tan","nat"},{"bat"}}},
        {{""},{{""}}},{{"a"},{{"a"}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.groupAnagrams(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
