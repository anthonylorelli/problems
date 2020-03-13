// 0930. Binary Subarrays With Sum
// Problem definition: https://leetcode.com/problems/binary-subarrays-with-sum/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <iostream>

class Solution {
    constexpr int summation(int n) {
        return (n * (n + 1)) / 2;
    }

public:
    int numSubarraysWithSum(std::vector<int>& A, int S) {
        int sum {0}, count {0};
        for (size_t i {0}, j {0}, b{0}; j < A.size(); ++j) {
            sum += A[j];

            if (sum == S) {
                while (i < j && A[i] == 0) {
                    ++i;
                }
                int e = ++j;
                while (e < A.size() && A[e] == 0) {
                    ++e;
                }

                size_t leftCount {i - b}, rightCount {e - j};
                count += i == j ? summation(leftCount + rightCount) : 
                    (1 + leftCount + rightCount + (leftCount * rightCount));
                std::cout << "b " << b << " i " << i << " j " << j << " e " << e << "\n";
            }

            b = i;
            sum -= A[i++];
        }

        return count;
    }
};

TEST_CASE("LC test cases", "[Binary Subarrays With Sum]") {
    std::vector<std::pair<std::pair<std::vector<int>,int>,int>> input {
        //{{{0,0,0,1,1,0,0,},2},12},{{{0,0,0,1,0,1,0,0,},2},12},{{{1,0,1,0,1},2},4},
        //{{{0},1},0},{{{1},1},1},{{{0,0,0},0},6},{{{0,0,0,0,0},0},15},
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
