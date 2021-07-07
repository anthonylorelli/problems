// 0097. Interleaving String
// Problem definition: https://leetcode.com/problems/interleaving-string/
// Accepted 2021-07-05 (based on representative solution)
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        std::vector<bool> dp(s2.length() + 1, false);
        for (int32_t i {0}; i <= s1.length(); ++i) {
            for (int32_t j {0}; j <= s2.length(); ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s2.length()];
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::string,std::string,std::string,bool>> input {
        {"aabcc", "dbbca", "aadbbcbcac", true},
        {"aabcc", "dbbca", "aadbbbaccc", false},
        {"", "", "", true}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [s1, s2, s3, expected] = p;
                REQUIRE(s.isInterleave(s1, s2, s3) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
