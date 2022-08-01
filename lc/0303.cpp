// 0303. Range Sum Query - Immutable
// Problem definition: https://leetcode.com/problems/range-sum-query-immutable/
// Accepted 2022-07-31
#define CATCH_CONFIG_RUNNER
#include "../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) {
        std::inclusive_scan(nums.begin(), nums.end(), std::back_inserter(m_v));
    }
    
    int sumRange(int left, int right) {
        return m_v[right + 1] - m_v[left];
    }

private:
    std::vector<int> m_v = {0};
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// TEST_CASE("LC test cases", "[Core]") {
//     std::vector<std::tuple<std::vector<int>,int>> input {
//         {{7,1,5,3,6,4},5},{{7,6,4,3,1},0}
//     };

//     SECTION("LC test cases") {
//         std::for_each(std::begin(input), std::end(input),
//             [&input](auto& p) {
//                 Solution s;
//                 auto& [testInput, expected] = p;
//                 REQUIRE(s.maxProfit(testInput) == expected);
//             });
//     }
// }

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    return Catch::Session().run(argc, argv);
}
