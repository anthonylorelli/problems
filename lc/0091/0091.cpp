// 0091. Decode Ways
// Problem definition: https://leetcode.com/problems/decode-ways/
// Accepted 2019-07-27

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
private:
    int countDecodings(const std::vector<int>& v, const size_t i, std::vector<int>& count) {
        if (i >= v.size()) {
            return 1;
        } else if (!count[i]) {
            int n {v[i]};

            if (n == 0) return 0;

            int answer {0};
            bool lastNumber {i == v.size() - 1};

            if ((!lastNumber && v[i + 1] != 0) || lastNumber) {
                answer += countDecodings(v, i + 1, count);
            }
            if (!lastNumber && (n * 10) + v[i + 1] <= 26) {
                answer += countDecodings(v, i + 2, count);
            }

            count[i] = answer;
        }

        return count[i];
    }
public:
    int numDecodings(std::string s) {
        std::vector<int> v(s.length(), 0);
        std::transform(s.begin(), s.end(), v.begin(), [](const auto& c) { return c - '0'; });
        std::vector<int> count(v.size(), 0);

        return countDecodings(v, 0, count);
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
    SECTION("LC test case 3") {
        Solution s;
        std::string i {"0"};
        REQUIRE(s.numDecodings(i) == 0);
    }
    SECTION("Local test case 1") {
        Solution s;
        std::string i {"1226"};
        REQUIRE(s.numDecodings(i) == 5);
    }
    SECTION("Local test case 2") {
        Solution s;
        std::string i {"1010"};
        REQUIRE(s.numDecodings(i) == 1);
    }
    SECTION("Local test case 3") {
        Solution s;
        std::string i {"101010101010101010101010101010101010101010101010101010101010101010"};
        REQUIRE(s.numDecodings(i) == 1);
    }
    SECTION("Local test case 4") {
        Solution s;
        std::string i {"907"};
        REQUIRE(s.numDecodings(i) == 0);
    }
    SECTION("Local test case 4") {
        Solution s;
        std::string i {"12212121212304"};
        REQUIRE(s.numDecodings(i) == 0);
    }
}
