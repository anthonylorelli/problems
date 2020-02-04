// 0581. Shortest Unsorted Continuous Subarray
// Problem definition: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        int min {10001}, max {0};
        auto p1 = std::adjacent_find(nums.begin(), nums.end(), std::greater{});
        std::cout << "First inflection " << p1 - nums.begin() << " Value " << *p1 << "\n";
        if (p1 != nums.end()) { min = *std::min_element(p1 + 1, nums.end()); }
        std::cout << "Min " << min << "\n";
        auto p2 = std::adjacent_find(nums.rbegin(), nums.rend(), std::less{});
        std::cout << "Second inflection " << nums.rend() - p2 << " Value " << *p2 << "\n"; 
        if (p2 != nums.rend()) { max = *std::max_element(p2 + 1, nums.rend()); }
        std::cout << "Max " << max << "\n";
        auto start = std::find_if(nums.begin(), p1 + 1, std::bind(std::less{}, _1, min));
        auto end = std::find_if(nums.rbegin(), p2 + 1, std::bind(std::greater{}, _1, max));
        int r {nums.rend() - end}, l {start - nums.begin()};
        return r - l < 0 ? 0 : r - l + 1;
    }
};

TEST_CASE("LC test cases", "[Shortest Unsorted Continuous Subarray]") {
    std::vector<std::pair<std::vector<int>,int>> input {
        {{2, 6, 4, 8, 10, 9, 15},5},{{8,9,10,1,2,3,4,5,6,7},10}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) { 
                Solution s;
                auto& [testInput, expected] = p;
                REQUIRE(s.findUnsortedSubarray(testInput) == expected);
            });
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
