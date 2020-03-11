// 0930. Binary Subarrays With Sum
// Problem definition: https://leetcode.com/problems/binary-subarrays-with-sum/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
    constexpr int summation(int n) {
        return (n * (n + 1)) / 2;
    }

public:
    int numSubarraysWithSum(std::vector<int>& A, int S) {
        int sum {0}, count {0};
        for (size_t i {0}, j {0}; i < A.size(); ++i) {
            if (A[i]) {
                sum++;
            } 

            if (sum == S) {
                int right = ++i;
                while (i < A.size() && A[i] == 0) {
                    ++i;
                }
                int left = j;
                while (j < right && A[j] == 0) {
                    ++j;
                }

                size_t leftCount {j - left}, rightCount {i - right};
                count += j == right ? summation(leftCount + rightCount) : 
                    (1 + leftCount + rightCount + (leftCount * rightCount));

                sum--;
                i--;
                if (left == j) { 
                    ++j;
                }
            }
        }

        return count;
    }
};

TEST_CASE("LC test cases", "[Binary Subarrays With Sum]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,int>> input {
        {{{0,0,0,1,1,0,0,},2},12},{{{0,0,0,1,0,1,0,0,},2},12},{{{1,0,1,0,1},2},4},
        {{{0},1},0},{{{1},1},1},{{{0,0,0},0},6},{{{0,0,0,0,0},0},15},
        {{{0,0,0,0,0,0,1,0,0,0},0},27}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.numSubarraysWithSum(testInput.first, testInput.second) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
