// 0740. Delete and Earn
// Problem definition: https://leetcode.com/problems/delete-and-earn/
// Accepted 2021-01-15
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        std::vector<int> count(10001, 0);
        for (const int n : nums) {
            count[n]++;
        }
        int use {0}, avoid {0}, prev {-1};

        for (int k {1}; k <= 10000; ++k) {
            if (count[k] == 0) { continue; }
            int m = std::max(avoid, use);
            use = (k - 1 != prev) ? k * count[k] + m : k * count[k] + avoid;
            avoid = m;
            prev = k;
        }

        return std::max(avoid, use);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,int>> input {
        {{3,4,2},6},
        {{2,2,3,3,3,4},9}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.deleteAndEarn(testInput) == expected);
            });
    }
}

auto speed=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
