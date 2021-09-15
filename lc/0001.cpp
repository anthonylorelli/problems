// 0001. Two Sum
// Problem definition: https://leetcode.com/problems/two-sum/
// Accepted 2019-07-29

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> m;
        std::vector<int> a(2);
        for (size_t i {0}; i < nums.size(); ++i) { m[nums[i]] = i; }
        for (size_t i {0}; i < nums.size(); ++i) {
            int delta {target - nums[i]};
            if (m.count(delta) && m[delta] != i) { 
                a[0] = i; a[1] = m[delta];
                break;
            }
        }
        return a;
    }
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}

TEST_CASE("", "[Subarray Sum Equals K]") {
    SECTION("LC test case 1") {
        Solution s;
        std::vector<int> v = {2, 7, 11, 15};
        std::vector<int> a = {0, 1};
        REQUIRE(s.twoSum(v, 9) == a);
    }
    SECTION("Local test case 1") {
        Solution s;
        std::vector<int> v = {2, 7, 11, 15};
        std::vector<int> a = {2, 3};
        REQUIRE(s.twoSum(v, 26) == a);
    }
    SECTION("Local test case 1") {
        Solution s;
        std::vector<int> v = {2, 7, 11, 1, 3, 4, 115};
        std::vector<int> a = {0, 4};
        REQUIRE(s.twoSum(v, 5) == a);
    }
    SECTION("Local test case 1") {
        Solution s;
        std::vector<int> v = {2, 7, 11, 1, 3, 4, 115};
        std::vector<int> a = {0, 4};
        REQUIRE(s.twoSum(v, 5) == a);
    }
}
