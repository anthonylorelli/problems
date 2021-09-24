// 0066. Plus One
// Problem definition: https://leetcode.com/problems/plus-one/
// Accepted 2021-09-23
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if (all_nines(digits)) {
            std::vector<int> result(digits.size() + 1, 0);
            result[0] = 1;
            return result;
        }
        std::vector<int> result(digits.size());
        int32_t carry {1};
        std::transform(digits.rbegin(), digits.rend(), result.rbegin(), [&carry](const auto n) {
            int32_t next = n + carry;
            carry = next / 10;
            next = next % 10;
            return next;
        });
        return result;
    }

    bool all_nines(std::vector<int>& digits) {
        for (const auto d : digits) {
            if (d != 9) { return false; }
        }
        return true;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>>> input {
        {{1,2,3},{1,2,4}},{{4,3,2,1},{4,3,2,2}},{{0},{1}},{{9},{1,0}},
        {{9,9,9,9},{1,0,0,0,0}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.plusOne(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
