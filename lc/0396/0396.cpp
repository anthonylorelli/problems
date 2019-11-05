// 0396. Rotate Function
// Problem definition: https://leetcode.com/problems/rotate-function/
// Accepted 2019-11-04
// Cf. https://leetcode.com/problems/rotate-function/discuss/87842/Java-Solution-O(n)-with-non-mathametical-explaination

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& A) {
        auto size {A.size()};
        long sum {0}, iteration {0};
        for (size_t i {0}; i < size; ++i) {
            sum += A[i];
            iteration += (A[i] * i);
        }
        long max {iteration}; 
        for (size_t i {1}; i < size; ++i) {
            iteration = iteration - sum + A[i-1] * size;
            max = std::max(max, iteration);
        }
        return size ? max : 0;
    }
};

TEST_CASE("LC test cases", "[Rotate Function]") {
    Solution s;
    std::vector<std::pair<std::vector<int>,int>> input {
        {{4,3,2,6}, 26}, {{-4,-3,-2,-6}, -16}, {{}, 0}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&s, &input](auto& p) { 
                REQUIRE(s.maxRotateFunction(p.first) == p.second); 
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
