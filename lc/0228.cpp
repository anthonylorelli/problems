// 0228. Summary Ranges
// Problem definition: https://leetcode.com/problems/summary-ranges/
// Accepted 2021-06-26
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        while_element(nums.begin(), nums.end(), [&](const auto& begin, const auto& end) {
            std::string range{std::to_string(*begin)};
            auto right = find_end_range(begin, end);
            if (begin != right) {
                range += "->";
                range += std::to_string(*right);
            }
            result.push_back(range);
            return right;
        });
        return result;
    }

    template <typename T, typename U>
    void while_element(T begin, T end, const U& action) {
        while (begin != end) {
            begin = action(begin, end) + 1;
        }
    }

    template <typename T>
    T find_end_range(T begin, T end) {
        auto right = std::adjacent_find(begin, end, [](const auto& a, const auto& b) {
            return a != (b - 1);
        });
        return right == end ? right - 1 : right;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<std::string>>> input {
        {{0,1,2,4,5,7},{"0->2","4->5","7"}},
        {{0,2,3,4,6,8,9},{"0","2->4","6","8->9"}},
        {{0,1,2,3,4},{"0->4"}},
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

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
