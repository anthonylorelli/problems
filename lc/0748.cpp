// 0748. Shortest Completing Word
// Problem definition: https://leetcode.com/problems/shortest-completing-word/
// Accepted 2021-05-03
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

class Solution {
public:
    std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string>& words) {
        int32_t counts[26]{};
        for (const auto c : licensePlate) {
            if (std::isalpha(c)) {
                counts[std::tolower(c) - 'a']++;
            }
        }
        std::string* answer {nullptr};
        for (auto& word : words) {
            int32_t word_count[26]{};
            for (const auto c : word) {
                word_count[c - 'a']++;
            }
            auto found = std::equal(std::begin(counts), std::end(counts), 
                std::begin(word_count), std::end(word_count),
                [](const auto n1, const auto n2) { return !(n1 > n2); });

            if (found) {
                answer = !answer ? &word : answer->length() > word.length() ? &word : answer;
            }
        }
        return *answer;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::vector<std::string>,std::string>> input {
        {"1s3 PSt",{"step","steps","stripe","stepple"},"steps"},
        {"1s3 456",{"looks","pest","stew","show"},"pest"},
        {"Ah71752",{"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"},"husband"},
        {"iMSlpe4",{"claim","consumer","student","camera","public","never","wonder","simple","thought","use"},"simple"}
    };

    SECTION("Test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&](auto& p) {
                auto& [testInput, words, expected] = p;
                REQUIRE(Solution{}.shortestCompletingWord(testInput, words) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
