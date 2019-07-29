// 0560. Subarray Sum Equals K
// Problem definition: https://leetcode.com/problems/subarray-sum-equals-k/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int sum {0}, answer {0};
        for (size_t current {0}, left {0}; current < nums.size(); ++current) {
            sum += nums[current];
            while (sum > k && left < current) { sum -= nums[left++]; }
            if (sum == k) { 
                while (!nums[left] && left < current) { left++; answer++; }
                answer++; 
            }
        }
        return answer;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Subarray Sum Equals K]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {1, 1, 1};
        REQUIRE(s.subarraySum(v, 2) == 2);
    }
    SECTION("LC test case 2") {
        Solution s;
        std::vector<int> v = {1};
        REQUIRE(s.subarraySum(v, 0) == 0);
    }
    SECTION("LC test case 3") {
        Solution s;
        std::vector<int> v = {-1, -1, 1};
        REQUIRE(s.subarraySum(v, 0) == 1);
    }
    SECTION("LC test case 4") {
        Solution s;
        std::vector<int> v = {-1, -1, 2};
        REQUIRE(s.subarraySum(v, 0) == 1);
    }
    SECTION("Local test case 1") {
        Solution s;
        std::vector<int> v = {1, 1, 1, 1, 1, 1};
        REQUIRE(s.subarraySum(v, 2) == 5);
    }
    SECTION("Local test case 2") {
        Solution s;
        std::vector<int> v = {1, 0, 1, 0, 1, 0, 1, 2};
        REQUIRE(s.subarraySum(v, 2) == 8);
    }
}
