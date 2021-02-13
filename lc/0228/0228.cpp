// 0228. Summary Ranges
// Problem definition: https://leetcode.com/problems/summary-ranges/
// Accepted ?
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        for (auto left {nums.begin()}; left != nums.end(); ) {
            std::string value {std::to_string(*left)};
            auto right = std::adjacent_find(left, nums.end(), [](const auto& a, const auto& b) {
                return (a + 1) != b;
            });
            if (right == nums.end()) {
                
            }
            if (left != right) {
                value += "->";
                value += std::to_string(*right);
            }
            result.push_back(value);
            left = right + 1;
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<std::string>>> input {
        {{0,1,2,4,5,7},{"0->2","4->5","7"}},
        {{0,2,3,4,6,8,9},{"0","2->4","6","8->9"}},
        {{},{}},
        {{-1},{"-1"}},
        {{0},{"0"}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.summaryRanges(testInput) == expected);
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
