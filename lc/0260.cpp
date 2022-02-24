// 0260. Single Number III
// Problem definition: https://leetcode.com/problems/single-number-iii/
// Accepted 2020-11-25
// Cf. https://leetcode.com/problems/single-number-iii/discuss/68921/C%2B%2B-solution-O(n)-time-and-O(1)-space-easy-understaning-with-simple-explanation
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int pattern {0}; 
        for (const auto n : nums) { pattern ^= n; }
        int last_bit = pattern & (-pattern);  // the last bit that a diffs b
        std::vector<int> answer {0,0};
        for (const auto n : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (n & last_bit) { answer[0] ^= n; }
            else { answer[1] ^= n; }
        }
        return answer;
    }

    std::vector<int> singleNumberOrig(std::vector<int>& nums) {
        int pattern {0}; 
        for (const auto n : nums) { pattern ^= n; }
        int last_bit = (pattern & (pattern - 1)) ^ pattern;  // the last bit that a diffs b
        int first {0}, second {0};
        for (auto n : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (n & last_bit) { first = first ^ n; }
            else { second = second ^ n; }
        }
        return {first, second}; 
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::pair<std::vector<int>,std::vector<int>>> input {
        {{1,2,1,3,2,5},{3,5}},
        {{-1,0},{-1,0}},
        {{0,1},{1,0}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.singleNumber(testInput) == expected);
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
