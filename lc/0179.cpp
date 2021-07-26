// 0179. Largest Number
// Problem definition: https://leetcode.com/problems/largest-number/
// Accepted 2021-07-25
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> ss;
        std::transform(nums.begin(), nums.end(), std::back_inserter(ss), [](const auto n) {
            return std::to_string(n);
        });
        std::sort(ss.begin(), ss.end(), [](const auto& a, const auto& b) {
            return a + b > b + a;
        });
        if (ss[0] == "0") { return "0"; }
        std::string result;
        for (auto& s : ss) {
            result += s;
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::string>> input {
        {{10,2},"210"},{{3,30,34,5,9},"9534330"},{{1},"1"},{{10},"10"},
        {{0,0,0},"0"}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.largestNumber(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
