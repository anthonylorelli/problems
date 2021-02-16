// 0318. Maximum Product of Word Lengths
// Problem definition: https://leetcode.com/problems/maximum-product-of-word-lengths/
// Accepted 2021-02-15
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        if (words.empty()) { return 0; }
        std::vector<uint32_t> v(words.size());
        std::transform(words.begin(), words.end(), v.begin(), [](const auto& word) {
            uint32_t n{0};
            for (const auto c : word) {
                n |= 1 << (c - 'a');
            }
            return n;
        });
        size_t max {0};
        for (int32_t i {0}; i < v.size(); ++i) {
            for (int32_t j {i + 1}; j < v.size(); ++j) {
                if (v[i] & v[j]) { continue; }
                max = std::max(max, words[i].length() * words[j].length());
            }
        }
        return max;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<std::string>,int>> input {
        {{"abcw","baz","foo","bar","xtfn","abcdef"},16},
        {{"a","ab","abc","d","cd","bcd","abcd"},4},
        {{"a","aa","aaa","aaaa"},0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxProduct(testInput) == expected);
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
