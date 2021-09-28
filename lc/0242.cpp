// 0242. Valid Anagram
// Problem definition: https://leetcode.com/problems/valid-anagram/
// Accepted 2021-09-25
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <array>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::array<int32_t,26> chars{};
        for (const auto c : s) {
            chars[c - 'a']++;
        }
        for (const auto c : t) {
            chars[c - 'a']--;
        }
        auto it = std::find_if(chars.begin(), chars.end(), [](const auto n) { return n != 0; });
        return it == chars.end();
    }

    bool isAnagram_sort(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string,bool>> input {
        {"anagram", "nagaram", true}, {"rat", "car", false}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, b, expected] = p;
                REQUIRE(s.isAnagram(testInput, b) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
