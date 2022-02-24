// 0136. Single Number
// Problem definition: https://leetcode.com/problems/single-number/
// Accepted 2019-08-22

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int,int> map;
        for (const auto n : nums) {
            map[n]++;
        }
        for (const auto& p : map) {
            if (p.second == 1) { return p.first; }
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("LC test cases", "[Single Number]") {
    Solution s;
    SECTION("LC test case 1") {
        std::vector<int> i = {2, 2, 1};
        REQUIRE(s.singleNumber(i) == 1);
    }
    SECTION("LC test case 2") {
        std::vector<int> i = {4, 1, 2, 1, 2};
        REQUIRE(s.singleNumber(i) == 4);
    }
}

TEST_CASE("Local test cases", "[Single Number]") {
    Solution s;
    SECTION("Test case 1") {
    }
}
