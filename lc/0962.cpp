// 0962. Maximum Width Ramp
// Problem definition: https://leetcode.com/problems/maximum-width-ramp/
// Accepted 2020-04-06

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& A) {
        std::stack<int> s;
        s.push(A[0]);
        for (int i {1}; i < A.size(); ++i) {
            if (A[s.top()] > A[i]) {
                s.push(i);
            }
        }

        int ramp {0};
        for (int j = A.size() - 1; j >= 0; --j) {
            while (!s.empty() && A[j] >= A[s.top()]) {
                ramp = std::max(ramp, j - s.top());
                s.pop();
            }
        }
        return ramp;
    }

    int maxWidthRamp_sort(std::vector<int>& A) {
        std::vector<int> indices(A.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&A](const auto i, const auto j) {
            return A[i] == A[j] ? i < j : A[i] < A[j];
        });
        int ramp {0}, min = A.size();
        for (const auto n : indices) {
            ramp = std::max(ramp, n - min);
            min = std::min(min, n);
        }
        return ramp;
    }
};

TEST_CASE("LC test cases", "[Maximum Width Ramp]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{6,0,8,2,1,5},4},{{9,8,1,0,1,9,4,0,4,1},7},
        {{3,28,15,1,4,12,6,19,8,15,3,9,6,4,13,12,6,12,10,1,2,1,4,1,4,0,0,1,1,0},25}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.maxWidthRamp(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
