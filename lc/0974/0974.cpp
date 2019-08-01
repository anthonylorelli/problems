// 0974. Subarray Sums Divisible by K
// Problem definition: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& A, int K) {
        int answer {0};
        for (size_t i {0}; i < A.size(); ++i) {
            int sum {0};
            for (size_t j{i}; j < A.size(); ++j) {
                sum += A[j];
                if (sum % K == 0) { answer++; }
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
        std::vector<int> v = {4, 5, 0, -2, -3, 1};
        REQUIRE(s.subarraysDivByK(v, 5) == 7);
    }
}
