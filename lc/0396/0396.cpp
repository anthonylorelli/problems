// 0396. Rotate Function
// Problem definition: https://leetcode.com/problems/rotate-function/
// Accepted ?
// Cf. https://leetcode.com/problems/rotate-function/discuss/406537/python-and-c%2B%2B-simple-O(n)-solution

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <numeric>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& A) {
        int max {std::numeric_limits<int>::min()}; // should be smallest negative
        auto size {A.size()};
        for (int offset {0}; offset < size; ++offset) {
            int sum {0};
            for (int i {1}; i < size; ++i) {
                sum += i * A[(i + offset) % size];
            }
            max = std::max(max, sum);
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
