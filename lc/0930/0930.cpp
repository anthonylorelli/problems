// 0930. Binary Subarrays With Sum
// Problem definition: https://leetcode.com/problems/binary-subarrays-with-sum/
// Accepted 2020-03-14

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <iostream>

class Solution {
    constexpr int summation(int n) {
        return (n * (n + 1)) / 2;
    }

    int countZeros(std::vector<int>& A) {
        int count {0};
        for (size_t i {0}; i < A.size(); ++i) {
            if (A[i] == 0) {
                size_t start {i};
                while (i < A.size() && A[i] == 0) {
                    ++i;
                }
                count += summation(i - start);
            }
        }
        return count;
    }

public:
    int numSubarraysWithSum(std::vector<int>& A, int S) {
        if (S == 0) {
            return countZeros(A);
        }

        int sum {0}, count {0};
        for (size_t i {0}, j {0}; j < A.size(); ++j) {
            sum += A[j];
            
            if (sum == S) {
                size_t b {i};
                while (i <= j && A[i] == 0) {
                    ++i;
                }
                size_t e {++j};
                while (e < A.size() && A[e] == 0) {
                    ++e;
                }

                size_t leftCount {i - b}, rightCount {e - j};
                count += 1 + leftCount + rightCount + (leftCount * rightCount);

                while (i < j && sum == S) {
                    sum -= A[i++];
                }

                j = e - 1;
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
