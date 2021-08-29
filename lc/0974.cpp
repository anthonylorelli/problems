// 0974. Subarray Sums Divisible by K
// Problem definition: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Accepted 2019-08-01

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& A, int K) {
        std::vector<int> v(K);
        int sum {0}, answer {0};
        v[0] = 1;
        for (const auto n : A) {
            sum += n;
            int remainder {((sum % K) + K) % K};
            answer += v[remainder];
            v[remainder]++;
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
