// 0560. Subarray Sum Equals K
// Problem definition: https://leetcode.com/problems/subarray-sum-equals-k/
// Accepted 2019-07-28

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int answer {0};
        for (size_t i {0}; i < nums.size(); ++i) {
            int sum {0};
            for (size_t j {i}; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) { answer++; }
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
        REQUIRE(s.subarraySum(v, 2) == 9);
    }
}
