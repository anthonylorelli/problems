// 0338. Counting Bits
// Problem definition: https://leetcode.com/problems/counting-bits/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        if (n == 0) { return m_0; }
        if (n == 1) { return m_1; }

        std::vector<int> result = {0, 1, 1};
        
        for (int32_t i {3}; i <= n; ++i) {
            int32_t rem  {i % 2};
            int32_t pow {i / 2};
            if (rem == 0 && pow > 0) {
                result.push_back(1);
            } else {
                result.push_back(result[pow * 2] + result[rem]);
            }
        }
        return result;
    }

private:
    std::vector<int> m_0 = {0};
    std::vector<int> m_1 = {0, 1};
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<int,std::vector<int>>> input {
        {{2, {0,1,1}}, {5, {0,1,1,2,1,2}}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.countBits(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
