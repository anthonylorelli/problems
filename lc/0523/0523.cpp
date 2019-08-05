// 0523. Continuous Subarray Sum
// Problem definition: https://leetcode.com/problems/continuous-subarray-sum/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        if (nums.size() < 2) { return false; }
        std::unordered_map<int,size_t> m;
        int sum {0};
        const int ak {k < 0 ? -k : k};
        m[0] = 0;
        for (size_t i {0}; i < nums.size(); ++i) {
            sum += nums[i];
            if (i > 0 && nums[i] == 0 && nums[i-1] == 0) { return true; }
            if (ak) {
                int remainder {sum % ak};
                if (m.count(remainder) && (i - m[remainder] > 1)) { return true; }
                if (!m.count(remainder)) { m[remainder] = i; }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Continuous Subarray Sum]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {23, 2, 4, 6, 7};
        REQUIRE(s.checkSubarraySum(v, 6));
    }
    SECTION("LC test case 2") {
        Solution s;
        std::vector<int> v = {23, 2, 4, 6, 7};
        REQUIRE(s.checkSubarraySum(v, 6));
    }
    SECTION("Local test case 1") {
        Solution s;
        std::vector<int> v = { };
        REQUIRE_FALSE(s.checkSubarraySum(v, 6));
    }
    SECTION("Local test case 2") {
        Solution s;
        std::vector<int> v = { 1 };
        REQUIRE_FALSE(s.checkSubarraySum(v, 6));
    }
    SECTION("Local test case 3") {
        Solution s;
        std::vector<int> v = { 6 };
        REQUIRE_FALSE(s.checkSubarraySum(v, 6));
    }
    SECTION("Local test case 4") {
        Solution s;
        std::vector<int> v = { 1, 6 };
        REQUIRE_FALSE(s.checkSubarraySum(v, 6));
    }
    SECTION("Local test case 5") {
        Solution s;
        std::vector<int> v = { 1, 4, 2 };
        REQUIRE(s.checkSubarraySum(v, 6));
    }
    SECTION("Local test case 6") {
        Solution s;
        std::vector<int> v = { 1, 4, 2 };
        REQUIRE_FALSE(s.checkSubarraySum(v, 0));
    }
    SECTION("Local test case 7") {
        Solution s;
        std::vector<int> v = { 0, 0 };
        REQUIRE(s.checkSubarraySum(v, 0));
    }
    SECTION("Local test case 8") {
        Solution s;
        std::vector<int> v = { 1, 0, 0 };
        REQUIRE(s.checkSubarraySum(v, 0));
    }
    SECTION("Local test case 9") {
        Solution s;
        std::vector<int> v = { 1, 1 };
        REQUIRE(s.checkSubarraySum(v, -1));
    }
}
