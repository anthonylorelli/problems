// 0739. Daily Temperatures
// Problem definition: https://leetcode.com/problems/daily-temperatures/
// Accepted ?
// Cf. https://leetcode.com/problems/daily-temperatures/discuss/384123/100-Speed-and-100-Space-C%2B%2B
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& T) {
        if (T.empty()) { return {}; }
        return {};
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>>> input {
        {{73, 74, 75, 71, 69, 72, 76, 73},{1, 1, 4, 2, 1, 1, 0, 0}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.dailyTemperatures(testInput) == expected);
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
