// 0229. Majority Element II
// Problem definition: https://leetcode.com/problems/majority-element-ii/
// Accepted 2021-02-05
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::vector<int> result;
        std::sort(nums.begin(), nums.end());

        for (auto start {nums.begin()}; start != nums.end();) {
            auto count = std::count(start, nums.end(), *start); 
            if (count > (nums.size() / 3)) {
                result.push_back(*start);
            }
            start += count;
        }
        return result;
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>>> input {
        {{3,2,3},{3}},
        {{1},{1}},
        {{1,2},{1,2}},
        {{1,2,3,4},{}},
        {{1,2,3},{}},
        {{1,1,2,3},{1}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.majorityElement(testInput) == expected);
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
