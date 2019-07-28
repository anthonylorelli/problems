// 0091. Decode Ways
// Problem definition: https://leetcode.com/problems/decode-ways/
// Accepted 2019-07-26
// Adapted from: https://leetcode.com/problems/product-of-array-except-self/discuss/148153/C%2B%2B-solution-O(n)-without-extra-space-with-explanation

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        std::vector<int> v(s.length(), 0);
        std::transform(s.begin(), s.end(), v.begin(), [](const auto& c) { return c - '0'; });
        int answer {0};
        for (size_t i {0}; i < v.size(); ++i) {
            int n {v[i]};
            if (n) { answer++; }
            if (i < (v.size() - 1) && (n*10 + v[i+1]) <= 26) { answer++; }
        }
        return answer;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Product of Array Except Self]") {
    SECTION("LC test case 1") {
        Solution s;
        std::string i {"12"};
        REQUIRE(s.numDecodings(i) == 2);
    }
    SECTION("LC test case 2") {
        Solution s;
        std::string i {"226"};
        REQUIRE(s.numDecodings(i) == 3);
    }
}
