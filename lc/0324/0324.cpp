// 0421. Wiggle Sort II
// Problem definition: https://leetcode.com/problems/wiggle-sort-ii/
// Accepted ?
// Cf. https://leetcode.com/problems/wiggle-sort-ii/discuss/494141/C%2B%2B%3A-Virtual-indexing-64ms
#define CATCH_CONFIG_RUNNER
#include "../../inc/catch.hpp"

#include <algorithm>
#include <numeric>
#include <vector>
#include <limits>

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        auto size {nums.size()};
        std::nth_element(nums.begin(), nums.begin() + size / 2, nums.end());

        int m {*(nums.begin() + (size / 2))};
        for (int i = 0, l = 0, r = size - 1; i <= r;) {
            if (nums[index(i, size)] > m) {
                std::swap(nums[index(i++, size)], nums[index(l++, size)]);
            } else if (nums[index(i,size)] < m) {
                std::swap(nums[index(i, size)], nums[index(r--,size)]);
            } else {
                i++;
            }
        }
    }

    constexpr size_t index(int32_t i, size_t size) {
        return (1 + 2*(i)) % (size | 1);
    }
};

TEST_CASE("LC test cases", "[Core]") {
    std::vector<std::tuple<std::vector<int>,std::vector<int>>> input {
        {{1,5,1,1,6,4},{1,5,1,6,1,4}},
        {{1,3,2,2,3,1},{2,3,1,3,1,2}}
    };

    SECTION("LC test cases") {
        std::for_each(std::begin(input), std::end(input),
            [&input](auto& p) {
                Solution s;
                auto& [testInput, expected] = p;
                s.wiggleSort(testInput);
                REQUIRE(testInput == expected);
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
